# Simple Text Editor

Simple Text Editor is a text editor application built using C++ and Qt framework. It allows users to create, open, edit, and save text files with standard text editing functionalities. I want to add several more features to it but I'll do it later. Also, if you want to help me related to this, feel free to add :D

## Features

- Create new text files
- Open existing text files
- Save text files
- Save text files with a different name
- Undo and redo text editing actions
- Cut, copy, and paste text
- Search for text within the document

## Requirements

- Qt framework (>= 5.0)
- You can install it from it's official website. Older versions got their offline installers but newer versions requires credit.

## Installation

1. Clone the repository:

```bash
    git clone https://github.com/your_username/simple-text-editor.git
```

2. Open the project in Qt Creator.

3. Build the project.

4. To run the executable, you would need several DLLs which are tough to compile in one place, so it is advised to run this wish the Qt Creator.

## Usage

1. Run the compiled executable.

2. Use the File menu to create a new file, open an existing file, save, or save as.

3. Use the Edit menu or keyboard shortcuts for undo, redo, cut, copy, paste, and search functionalities.

## Project Structure

- `TextEditor.h` and `TextEditor.cpp`: Main class for the text editor functionality.
- `SearchDialog.h` and `SearchDialog.cpp`: Dialog for searching text within the document.
- `ui_TextEditor.h`: UI header generated by Qt Designer.
- `ui_SearchDialog.h`: UI header generated by Qt Designer.
- `main.cpp`: Entry point of the application.
- `TextEditor.pro`: Qt project file.
