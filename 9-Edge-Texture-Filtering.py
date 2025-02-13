import cv2 
import numpy as np 
 
# Load the image 
img = cv2.imread("flower.jpg") 
 
# Convert the image to grayscale 
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 
 
# Edge detection 
edges = cv2.Canny(gray, 100, 200)  
 
# Texture extraction 
kernel = np.ones((5, 5), np.float32) / 25 # Define a 5x5 averaging kernel 
texture = cv2.filter2D(gray, -1, kernel) # Apply the averaging filter for texture extraction 
 
# Display the original image, edges, and texture 
cv2.imshow("Original Image", img) 
cv2.imshow("Edges", edges) 
cv2.imshow("Texture", texture) 
 
# Wait for a key press and then close all windows 
cv2.waitKey(0) 
cv2.destroyAllWindows()