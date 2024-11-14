import tkinter as tk
import os
from copy import deepcopy
from casteljau import bezier_curve

def normalize(max_x, max_y, min_x, min_y, points):
    l = max_x - min_x
    h = max_y - min_y

    for curve in points:
        for point in curve:
            point[0] -= min_x
            point[1] -= min_y
            point[0] /= l
            point[1] /= h


def load_points(path):
    points = []
    with open(path, 'r') as file:
        data = (line.rstrip() for line in file.readlines())
    curve = []
    max_x = float('-inf')
    max_y = float('-inf')
    min_x = float('inf')
    min_y = float('inf')
    for line in data:
        if line == ';':
            if curve != []:
                points.append(curve)
            curve = []
        else:
            cords = line.split(',')
            x = int(cords[0])
            y = int(cords[1])
            if  x > max_x: max_x = x
            elif x < min_x: min_x = x

            if y > max_y: max_y = y
            elif y < min_y: min_y = y

            curve.append([x, y])
    normalize(max_x, max_y, min_x, min_y, points)
    return points

POINTS_FOLDER_PATH = 'letters_txt/'

def l_dict(folder_path):
    letters_points = {'' : []}
    avaliable_l = ''
    files = os.listdir(folder_path)
    for file_name in files:
        file_path = os.path.join(folder_path, file_name)
        if os.path.isfile(file_path):
            letters_points[file_name[0]] = load_points(folder_path + file_name)
            avaliable_l += file_name[0] + ', '
    avaliable_l = avaliable_l[:-2]
    del letters_points['']
    return letters_points, avaliable_l

def move_l(letter, x, y):
    for curve in letter:
        for coord in curve:
            coord[0] += x
            coord[1] += y

class TextMain:
    def __init__(self, root):
        self.root = root
        self.canvas = tk.Canvas(self.root, width=1025, height=650)
        self.canvas.pack()

        self.current_letter = None
        self.root.bind("<Return>", self.on_enter_press)
        self.root.bind("<BackSpace>", self.on_backspace_press)
        self.root.bind("<Key>", self.on_key_press)

        self.l_size = 100
        self.l_points = l_dict(POINTS_FOLDER_PATH)[0]
        self.scale_points(self.l_points, self.l_size)
        self.l_avaliable = l_dict(POINTS_FOLDER_PATH)[1]
        self.lines_count = 0
        self.current_text = [""]
        self.cursor_id = None

        self.canvas.create_text(512, 630, text="Letters avaliable: "+self.l_avaliable, anchor="center", font=("Arial", 20))

    def scale_points(self, letter_dict, scale):
        for letter, points in letter_dict.items():
            for curve in points:
                for coord in curve:
                    coord[0] *= scale
                    coord[1] *= scale

    def on_backspace_press(self, event): 
        if self.current_text:
            s = self.current_text[-1]
            self.current_text[-1] = s[:-1]  
            self.canvas.delete("letter") 
            self.display_text() 
            if self.current_text[-1] == "":
                self.current_text = self.current_text[:-1]
                self.lines_count -= 1
                self.canvas.delete("letter") 
                self.display_text()

    def on_enter_press(self, event):
        self.lines_count += 1
        self.current_text.append("")

    def draw_bezier_curve(self, control_points):
        curve_x, curve_y = bezier_curve(control_points)
        curve_points = []
        for x, y in zip(curve_x, curve_y):
            curve_points.extend([x, y])
        self.canvas.create_line(*curve_points, fill='black', width=2, tags="bezier_curve")

    def draw_l_bezier(self, letter):
        for curve in letter:
            self.draw_bezier_curve(curve)

    def draw_letter(self, points):
        self.canvas.create_line(points, fill="black", tags="letter")

    def draw_cursor(self, x, y1, y2):
        self.cursor_id = self.canvas.create_line(x, y1, x, y2, fill="red", tags="cursor")

    def on_key_press(self, event):
        if event.char.isalpha() and event.char.lower() in self.l_points:
            self.current_text[self.lines_count] += event.char.lower()
            self.display_text()

    def display_text(self):
        self.canvas.delete("all")
        self.canvas.create_text(512, 630, text="Letters avaliable: "+self.l_avaliable, anchor="center", font=("Arial", 20))
        lines = 0
        i = 0
        for line in self.current_text:
            for letter in line:
                if letter in self.l_points:
                    curr_l_points = deepcopy(self.l_points[letter])
                    move_l(curr_l_points, (self.l_size)*i, (self.l_size)*lines+5)
                    self.draw_l_bezier(curr_l_points)
                    i += 1
                    self.move_cursor()
            i = 0
            lines += 1

    def move_cursor(self):
        text = self.current_text[self.lines_count] if self.current_text else "."
        text_width = len(text) * (self.l_size)
        cursor_x = text_width if self.current_text else self.l_size

        overall_height = (self.l_size) * (self.lines_count)

        if self.cursor_id:
            self.canvas.delete(self.cursor_id)

        self.draw_cursor(cursor_x, overall_height, (self.l_size) + overall_height)


def main():
    root = tk.Tk()
    root.title("Text editor")
    editor = TextMain(root)
    root.mainloop()

if __name__ == "__main__":
    main()
