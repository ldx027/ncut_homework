from PIL import Image

img = Image.open("a.png")
img.resize((100, 100))
img.show()