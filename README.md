# CLIPainter

CLIPainter is a Qt-based application for creating and managing graphical objects such as lines, rectangles, squares, and triangles. It allows command-line interactions for managing graphical items on a canvas and offers user-friendly log messages to learn the syntax of the special commands.

## Features

- Create lines, rectangles, squares, and triangles.
- Connect available objects on the canvas.
- Execute commands from files.

## Requirements

- Qt 6.7.2 or later

- CMake or Qmake(for qt 6) and Makefile

- C++ compiler

  The build process through cmake/qmake & makefile was tested on Ubuntu 24.04 LTS only.

## Installation

### Installing Qt

Ensure that Qt 6.7.2 is installed on your system. You can download it from the [Qt website](https://www.qt.io/download).

### Building the Project

1. Clone the repository:

    ```bash
    git clone https://github.com/gortadevosyan/CLIPainter.git
    ```

2. (Optional) Open the project through QT Creator and run.

3. Run CMake to configure the project:

    ```bash
    $cmake .. 
    #or
    $qmake -project 
    $qmake
    Alternatively try
    $qmake6 -project
    $qmake6
    ```

4. Build the project:

    ```bash
    $make
    ```

5. Run the application:

    ```bash
    ./CLIPainter
    ```

## Usage

- Launch the application to open the main window.

- Use the command line interface to create and manipulate graphical objects.

- Available commands include `create_line`, `create_rectangle`, `create_square`, `create_triangle`,  `connect` and ``execute_file``.

  ``Full list of commands``

  ``````bash
  #create line from (x1,y1) to (x2,y2)
  $create_line -name {line_name} -coord_1 {x1,y1} -coord_2 {x2,y2} 
  #create triangle with the given coordinates
  $create_triangle -name {triangle_name} -coord_1 {x1,y1} -coord_2 {x2,y2} -coord_3 {x3,y3}
  #creates a unique rectangle with the diagonal from (x1, y1) to (x2, y2) and sides parallel to x and y axis
  $create_rectangle -name {rect_name} -coord_1 {x1,y1} -coord_2 {x2,y2}
  #creates rectangle with the given coordinates
  $create_rectangle -name {rect_name} -coord_1 {x1,y1} -coord_2 {x2,y2} -coord_3 {x3,y3} -coord_4 {x4,y4}
  #creates the unique square with diagonal from (x1, y1) to (x2, y2)
  $create_square -name {sqr_name} -coord_1 {x1,y1} -coord_2 {x2,y2}
  #creates square with the given coordinates
  $create_square -name {sqr_name} -coord_1 {x1,y1} -coord_2 {x2,y2} -coord_3 {x3,y3} -coord_4 {x4,y4}
  #Connects the centers of two shapes with a straight line.
  $connect -object_name_1 {star_name} -object_name_2 {rect_name}
  #Executes multiple commands from a specified file, drawing the corresponding shapes on the canvas.
  $execute_file -file_path {../a/b/c/d/script.txt}
  #note, that by default,during execution the local address is under ../build/Desktop_Qt_6_7_2-Debug, hence the file location should be adjusted accortingly when relative path is used.
  ``````

  

## Known Issues

Line names are not displayed properly whenever it is parallel to the y axis. The reason behind this is the small size of the bounding rectangle of lines, which do not fit any characters. To fix this, one can adjust the minimum width of the bounding rectangle for line items, but for larger input names the issue will persist.
