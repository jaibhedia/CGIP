import cv2 

img = cv2.imread("./flower.jpg") 
original= img 
h, w, channels = img.shape 
half_width = w//2 
half_height = h//2 
 
TopLeft_quadrant = img[:half_height, :half_width] 
TopRight_quadrant = img[:half_height, half_width:]   
BottomLeft_quadrant = img[half_height:, :half_width] 
BottomRight_quadrant = img[half_height:, half_width:] 
 
cv2.imshow('originalImage',original) 
cv2.imshow('TopLeft_Quadrant', TopLeft_quadrant) 
cv2.imshow('TopRight_Quadrant', TopRight_quadrant) 
cv2.imshow('BottomLeft_Quadrant', BottomLeft_quadrant) 
cv2.imshow('BottomRight_Quadrant', BottomRight_quadrant) 
 
cv2.waitKey(0) 
cv2.destroyAllWindows()