from typing import AbstractSet
import cv2
import csv
import os
import matplotlib.pyplot as plt
from numpy.lib.function_base import kaiser
from numpy.lib.twodim_base import vander
from numpy.testing._private.utils import HAS_REFCOUNT, jiffies
from scipy.ndimage.morphology import _distance_tranform_arg_check
from skimage.metrics import structural_similarity as ssim
    
def structural_sim(img1, img2):
    img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
    img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
    s = ssim(img1, img2)
    return s

def sift_sim(img1, img2):
    sift = cv2.SIFT_create()
# find the keypoints and descriptors with SIFT
    kp1, des1 = sift.detectAndCompute(img1,None)
    kp2, des2 = sift.detectAndCompute(img2,None)
# BFMatcher with default params
    bf = cv2.BFMatcher()
    matches = bf.knnMatch(des1,des2,k=2)
# Apply ratio test
    good = []
    sf = 0
    for m,n in matches:
        if m.distance < 0.75*n.distance:
            good.append([m])
            g = len(good)
            sf=(g)/len(kp2)
    return sf

def orb_sim(img1, img2):
    orb = cv2.ORB_create()

    kp_a, desc_a = orb.detectAndCompute(img1, None)
    kp_b, desc_b = orb.detectAndCompute(img2, None)

    bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck = True)

    matches = bf.match(desc_a, desc_b)
    similar_reg = [i for i in matches if i.distance < 50]
    if len(matches) == 0:
        return 0
    o = len(similar_reg) / len(matches)
    return o

def compare_images(img1, img2):
    img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
    img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
    s = ssim(img1, img2)
     

    sift = cv2.SIFT_create()
# find the keypoints and descriptors with SIFT
    kp1, des1 = sift.detectAndCompute(img1,None)
    kp2, des2 = sift.detectAndCompute(img2,None)
# BFMatcher with default params
    bf = cv2.BFMatcher()
    matches = bf.knnMatch(des1,des2,k=2)
# Apply ratio test
    good = []
    sf = 0
    for m,n in matches:
        if m.distance < 0.75*n.distance:
            good.append([m])
            g = len(good)
            sf=(g)/len(kp2)
    


    plt.suptitle("SSIM: %.2f SIFT: %.2f" % (s, sf))
    img3 = cv2.drawMatchesKnn(img1,kp1,img2,kp2,good,None,flags = cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
    plt.imshow(img3),plt.show()
    return s, sf
	

#main


path = 'C:\\Users\\xrace\\Desktop\\coding\\image_matching\\Whatsapp\\test\\Data\\'

imgs = []
for r, d, f in os.walk(path):
    for file in f:
        if '.jpg' in file:
            imgs.append(os.path.join(r, file))

Base_icon = 'Whatsapp\\train\\Data\\whatsappp.jpg'
img1 = cv2.imread(Base_icon)
Heading = ['Icon_name', 'SSIM', 'SIFT', 'ORB']
rows = []

for f in imgs:
    img2 = cv2.imread(f) 
    #ssim_val, sift_val = compare_images(img1, img2)
    ssim_val = structural_sim(img1, img2)
    sift_val = sift_sim(img1, img2)
    orb_val = orb_sim(img1, img2)
    image_name = str(f).replace(path, '')
    rows.append([image_name , round(ssim_val, 2), round(sift_val, 2), round(orb_val, 2)])
icon = Base_icon.replace('.jpg', '')
with open(icon + '.csv', 'w') as csvfile: 
    csvwriter = csv.writer(csvfile) 
    csvwriter.writerow(Heading) 
    csvwriter.writerows(rows)

