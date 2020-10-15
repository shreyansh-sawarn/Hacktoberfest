from PIL import Image

dot_char = [' ', '.']

def convert(imagefile, new_width=100):
	image = Image.open(imagefile)
	width, height = image.size
	ratio = width/height
	new_height = int(new_width * ratio)
	image = image.resize((new_width, new_height))

	image = image.convert('L')
	pixels = image.getdata()
	characters = "".join([' ' if pixel < 100 else '.' for pixel in pixels])

	pixel_count = len(characters)
	ascii_image = "\n".join([characters[index:index+100] for index in range(0, pixel_count, 100)])
	print(ascii_image)


if __name__ == "__main__":
	convert("enter path to file here")
