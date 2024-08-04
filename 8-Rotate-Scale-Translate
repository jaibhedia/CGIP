import cv2 
import numpy as np 
 
def apply_rotation(image, angle): 
    height, width = image.shape[:2] 
    # Calculate the rotation matrix 
    rotation_matrix = cv2.getRotationMatrix2D((width/2, height/2), angle, 1) 
    rotated_image = cv2.warpAffine(image, rotation_matrix, (width, height)) 
    return rotated_image 
 
def apply_scaling(image, scale_x, scale_y): 
    scaled_image = cv2.resize(image, None, fx=scale_x, fy=scale_y) 
    return scaled_image 
 
def apply_translation(image, tx, ty): 
    translation_matrix = np.float32([[1, 0, tx], [0, 1, ty]]) 
    translated_image = cv2.warpAffine(image, translation_matrix, (image.shape[1], image.shape[0])) 
    return translated_image 
 
image = cv2.imread('flower.jpg') 
 
# Define the angle for rotation (in degrees) 
angle = 45 
 
# Define scaling factors 
scale_x = 1.5 
scale_y = 1.5 
 
# Define translation amounts (in pixels) 
tx = 50 
ty = 50 
 
# Apply rotation 
rotated_image = apply_rotation(image, angle) 
 
# Apply scaling 
scaled_image = apply_scaling(image, scale_x, scale_y) 
 
# Apply translation 
translated_image = apply_translation(image, tx, ty) 
 
# Display the original image and the modified images 
cv2.imshow('Original Image', image) 
cv2.imshow('Rotated Image', rotated_image) 
cv2.imshow('Scaled Image', scaled_image) 
cv2.imshow('Translated Image', translated_image) 
 
# Wait for a key press and then close all windows 
cv2.waitKey(0) 
cv2.destroyAllWindows()