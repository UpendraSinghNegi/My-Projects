import cv2

faceHar = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

img = cv2.imread('./WIN_20220620_21_27_33_Pro.jpg')

imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

faces = faceHar.detectMultiScale(imgGray,1.1,4)

for(x,y,w,h) in faces:
    cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)

cv2.imshow("Image",img)

cv2.waitKey(0)


