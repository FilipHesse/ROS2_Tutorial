# Name of the detected object's class
string class_name

# Confidence (in percentage) of the detected class for the object
float32 confidence

# Pixel coordinates of the box surrounding the detected object
# Array [x_1, y_1, x_2, y_2], with 1 and 2 corresponding to each vertex
uint16[4] bounding_box_coords