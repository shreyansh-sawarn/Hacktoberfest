import cv2
import numpy as np
import math

filename='C:/image.jpg'
img = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
cv2.namedWindow('main')
cv2.imshow('main', img)
cv2.waitKey(0)

MGR = np.array([[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]], dtype=np.float32)

def convolution(image, kernel):
    conv = np.zeros_like(image)

    padding = np.zeros((image.shape[0] + 2, image.shape[1] + 2), image.dtype)
    padding[0:-2, 0:-2] = image
    #cv2.namedWindow('main')
    #cv2.imshow('main', padding)
    #cv2.waitKey(0)

    for i in range(image.shape[1]):
        for j in range(image.shape[0]):
            conv[j,i]=(kernel*padding[j:j+3, i:i+3]).sum()
    return conv
img_edge=convolution(img,MGR)
cv2.namedWindow('main1')
cv2.imshow('main1', img_edge)
cv2.waitKey(0)