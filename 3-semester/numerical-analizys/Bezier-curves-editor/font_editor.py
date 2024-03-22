import matplotlib.pyplot as plt
import os
from casteljau import create_ponits, bezier_curve
from matplotlib.widgets import Button
from matplotlib.widgets import TextBox

"""
Right click - add a new point
Left click - select a point, move it
Middle click on a point - crate new curve with 
    this point as start point
ENTER - add a new curve
DELETE - delete the last point
SHIFT - clear everything and start over

PS: Please remember to press ENTER when adding a new curve,
or when you want to save image.
"""

IMAGE_PATH = 'backgr/a.png'


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, x, y):
        return ((self.x - x) ** 2 + (self.y - y) ** 2) ** (1/2)
    
    def __str__(self):
        return f'{self.x},{self.y}'

class FontMain:
    def __init__(self, image_path):
        
        self.points = {0: []}
        self.active_group_id = 0
        self.active_point = None
        self.image = plt.imread(image_path)
        

        self.fig, self.ax = plt.subplots()
        
        self.fig.canvas.mpl_connect('button_press_event', self.on_click)
        self.fig.canvas.mpl_connect('key_press_event', self.on_key)
        
        button_ax = plt.axes([0.8, 0.182, 0.15, 0.04])
        save_button = Button(button_ax, 'Save the letter')
        save_button.on_clicked(self.on_save_button_clicked)

        button_ax3 = plt.axes([0.8, 0.112, 0.15, 0.04])
        change_button = Button(button_ax3, 'Change the letter')
        change_button.on_clicked(self.on_change_button_clicked)

        button_ax2 = plt.axes([0.8, 0.252, 0.15, 0.04])
        bg_button = Button(button_ax2, 'Choose backgroud')
        bg_button.on_clicked(self.on_bg_button_clicked)


        self.fig.canvas.manager.set_window_title('Font editor')
        self.fig.set_size_inches(9, 6)
        self.update_plot()
    
        plt.show(block=True)

    def load_points(self, path):
        print("I'm here")
        self.points.clear()
        id = 0
        with open(path, 'r') as file:
            data = (line.rstrip() for line in file.readlines())
        point_group = []
        for line in data:
            if line == ';':
                self.points[id] = point_group.copy()
                point_group = []
                id += 1
            else:
                cords = line.split(',')
                point_group.append(Point(int(cords[0]), int(cords[1])))

    def save_points(self, path):
        with open(path, 'w') as file:
            for point_group in self.points.values():
                for point in point_group:
                    file.write(f'{point.x},{point.y}\n')
                file.write(';\n')

    def new_curve(self):
        new_id = max(self.points.keys()) + 1
        self.points[new_id] = []
        self.active_group_id = new_id

    def on_click(self, event):
        mouse_x, mouse_y = int(event.xdata), int(event.ydata)
        if event.button == 1:
            
            active_changed = False

            for id, point_group in self.points.items():
                for point in point_group:
                    if point.distance(mouse_x, mouse_y) < 5:
                        self.active_point = point
                        self.active_group_id = id
                        active_changed = True
                        break

            if not active_changed and self.active_point is not None:
                self.active_point.x = mouse_x
                self.active_point.y = mouse_y

        elif event.button == 2:
            existing_point_clicked = False

            for id, point_group in self.points.items():
                for point in point_group:
                    if point.distance(mouse_x, mouse_y) < 5:
                        existing_point_clicked = True
                        self.active_point = point
                        self.active_group_id = id
                        break

            if existing_point_clicked:
                self.new_curve() 

                self.points[self.active_group_id].append(self.active_point)
                
            else:
                new_point = Point(mouse_x, mouse_y)
                if self.active_point is not None:
                    self.points[self.active_group_id].insert(self.points[self.active_group_id].index(self.active_point), new_point)
                else:
                    if self.active_group_id in self.points:
                        self.points[self.active_group_id].append(new_point)
                        
                self.active_point = new_point

        elif event.button == 3:
            new_point = Point(mouse_x, mouse_y)
            if self.active_point is not None:
                self.points[self.active_group_id].insert(self.points[self.active_group_id].index(self.active_point), new_point)
            else:
                if self.active_group_id in self.points:
                    self.points[self.active_group_id].append(new_point)
                    
            self.active_point = new_point
                    
        self.update_plot()

    def on_key(self, event):
        if event.key == 'enter':
            self.active_group_id = max(self.points.keys()) + 1
            self.points[self.active_group_id] = []
            self.active_point = None
            self.update_plot()
        elif event.key == 'shift':
            self.points = {0: []}
            self.active_group_id = 0
            self.active_point = None
            plt.clf()
            self.update_plot()
        elif event.key == 'delete':
            self.points[self.active_group_id].remove(self.active_point)
            self.active_point = None
            self.update_plot()

    def on_save_button_clicked(self, event):
        text_box_fig, text_box_ax = plt.subplots()
        text_box_ax.axis('off')

        text_box_fig.set_size_inches(6, 1)
        text_box_fig.canvas.manager.set_window_title('Save the letter')
        
        text_ax = plt.axes([0.5, 0.5, 0.1, 0.3])
        self.text_box = TextBox(text_ax, 'Enter file name (what letter is this): ')
        plt.text(-4.15, -1.2, "* The file name should contain only one character, \nsymbolizing the letter's name. For example, 'a' or 'x'.", color='blue')

        def submit_image_name(image_name):
            name = 'letters_png/' + image_name + '.png'
            self.fig.savefig(name)

            path ='letters_txt/' + image_name + '.txt'
            with open(path, 'w') as file:
                for point_group in self.points.values():
                    for point in point_group:
                        file.write(f'{point.x},{point.y}\n')
                    file.write(';\n')

            plt.close(text_box_fig)

        self.text_box.on_submit(submit_image_name)
        plt.show()

    def on_bg_button_clicked(self, image_path):
        text_box_fig, text_box_ax = plt.subplots()
        text_box_ax.axis('off')

        text_box_fig.set_size_inches(6, 1)
        text_box_fig.canvas.manager.set_window_title('Choose background letter')
        
        text_ax = plt.axes([0.45, 0.4, 0.3, 0.3])
        self.text_box = TextBox(text_ax, 'Enter letter name:')

        def submit_image_name(image_name):
            path = 'backgr/' + image_name + ".png"
            self.image = plt.imread(path)
            plt.close(text_box_fig)

            self.update_plot()


        self.text_box.on_submit(submit_image_name)
        plt.show()

    def on_change_button_clicked(self, event):
        text_box_fig, text_box_ax = plt.subplots()
        text_box_ax.axis('off')

        text_box_fig.set_size_inches(6, 1)
        text_box_fig.canvas.manager.set_window_title('Change the letter')
        
        text_ax = plt.axes([0.45, 0.4, 0.3, 0.3])
        self.text_box = TextBox(text_ax, 'Enter letter name:')

        def submit_image_name(letter):
            path_p =  os.path.join('letters_txt/', letter + '.txt')
            if os.path.exists(path_p):
                self.load_points(path_p)
                path_b = 'backgr/' + letter + '.png'
                self.image = plt.imread(path_b)
            plt.close(text_box_fig)

            self.update_plot()

        self.text_box.on_submit(submit_image_name)
        plt.show()
    
    def add_save_button(self):
        button_ax = plt.axes([0.8, 0.182, 0.15, 0.04])
        save_button = Button(button_ax, 'Save the letter')
        save_button.on_clicked(self.on_save_button_clicked)

    def add_change_button(self):
        button_ax3 = plt.axes([0.8, 0.112, 0.15, 0.04])
        change_button = Button(button_ax3, 'Change the letter')
        change_button.on_clicked(self.on_change_button_clicked)

    def add_bg_button(self):
        button_ax2 = plt.axes([0.8, 0.252, 0.15, 0.04])
        bg_button = Button(button_ax2, 'Choose backgroud')
        bg_button.on_clicked(self.on_bg_button_clicked)
        
    def draw_bezier_curve(self, xps, yps, color, p_color):
        control_points = create_ponits(xps, yps)
        curve_x, curve_y = bezier_curve(control_points)
        plt.plot(curve_x, curve_y, label='Krzywa Béziera', color=color, linewidth=3)
        plt.scatter(*zip(*control_points), color=p_color, label='Punkty kontrolne', s=10)

    def update_plot(self):
        plt.clf()

        plt.imshow(self.image)

        for id, point_group in self.points.items():
            xps = [p.x for p in point_group]
            yps = [p.y for p in point_group]

            if len(point_group) >= 2:
                self.draw_bezier_curve(xps, yps, 'cyan' if id == self.active_group_id else 'blue',
                                       'magenta' if id == self.active_group_id else '#bab6ba')

        if self.active_point is not None:
            plt.scatter([self.active_point.x], [self.active_point.y], c='cyan', marker='o', s=10)

        self.add_save_button()
        self.add_bg_button()
        self.add_change_button()
 
        self.fig.canvas.draw()

if __name__ == "__main__":
    FontMain(IMAGE_PATH)