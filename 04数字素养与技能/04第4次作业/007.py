from PIL import Image

img = Image.open("a.png").convert('L')
img.show()