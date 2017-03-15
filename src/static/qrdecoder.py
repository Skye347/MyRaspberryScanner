from PIL import Image
import zbarlight

def decoder(a):
    with open(a,'rb') as image_file:
        image=Image.open(image_file)
        image.load()

    codes=zbarlight.scan_codes('qrcode',image)
    if(codes is None):
        return ''
    else:
        return codes[0]