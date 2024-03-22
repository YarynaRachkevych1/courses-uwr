import tkinter as tk
import os
from font_editor import FontMain
from text_editor import TextMain

IMAGE_PATH = 'backgr/empty.png'
SECOND_FILE_PATH = 'text_editor.py'

class MainMenu:
    def __init__(self, root):
        self.root = root
        self.root.title("Main Menu")
        self.root.geometry("350x250")
        
        button_width = 20
        button_height = 5

        self.open_editor_button = tk.Button(root, text="Open Font Editor", command=self.open_font_editor, width=button_width, height=button_height)
        self.open_editor_button.pack(pady=20)

        self.open_text_editor_button = tk.Button(root, text="Open Text Editor", command=self.open_text_editor, width=button_width, height=button_height)
        self.open_text_editor_button.pack(pady=20)

    def open_font_editor(self):
        FontMain(IMAGE_PATH)

    def open_text_editor(self):
        os.system('python {}'.format(SECOND_FILE_PATH)) 

    def show_main_menu(self):
        self.root.deiconify() 
        
def main():
    root = tk.Tk()
    app = MainMenu(root)
    root.mainloop()

if __name__ == "__main__":
    main()
