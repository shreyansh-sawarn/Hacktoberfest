import cv2
import numpy as np

filename='C:/image.jpg'
img = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
#p.zeros_like(image)


def summed_area_table(image):
    sum = np.zeros((image.shape[0] + 2, image.shape[1] + 2))
    sum[1:-1, 1:-1] = image
    for i in range(1,sum.shape[1]-1):
        for j in range(1,sum.shape[0]-1):
            sum[j,i]=image[j-1,i-1]+sum[j-1,i]+sum[j,i-1]-sum[j-1,i-1]
    return sum

sum=summed_area_table(img)
cv2.namedWindow('main')
cv2.imshow('main', sum)
cv2.waitKey(0)

def mean_intensity(sumt,p1,p2,p3,p4):
    #intensity_area=sumt[p1:p2,p3:p4]
    sum= sumt[p1+1,p2+1]+sumt[p1+1,p3+1]+sumt[p2+1,p4+1]+sumt[p3+1,p4+1]
    pixels=area_calc(p1,p2,p3,p4)
    mean=sum/pixels
    return mean
    #np.mean(intensity_area,


def area_calc(p1,p2,p3,p4):
    area=(p3-p2)*(p4-p1)
    return area

int1=mean_intensity(sum,0,0,500,500)
int2=mean_intensity(sum,300,300,800,800)
int3=mean_intensity(sum,0,400,800,1200)

print(int1)
print(int2)
print(int3)
