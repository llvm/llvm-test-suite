#!/bin/python3
import argparse
import os
import sys

try:
    import cv2
    import numpy as np
    from skimage.metrics import structural_similarity as ssim
except ImportError:
    print("One or more required packages are not installed. Please install them using the command:")
    print("pip install -r requirements.txt")
    sys.exit(1)

def mse(imageA, imageB):
    err = np.sum((imageA.astype("float") - imageB.astype("float")) ** 2)
    err /= float(imageA.shape[0] * imageA.shape[1] * imageA.shape[2])
    return err

def compare_images(image_path1, image_path2, ssim_threshold=0.9, mse_threshold=1000):
    image1 = cv2.imread(image_path1)
    image2 = cv2.imread(image_path2)
    
    if image1 is None or image2 is None:
        raise ValueError("One or both of the image paths are invalid.")
    
    if image1.shape != image2.shape:
        image2 = cv2.resize(image2, (image1.shape[1], image1.shape[0]))
    
    smaller_side = min(image1.shape[:2])
    win_size = smaller_side if smaller_side % 2 == 1 else smaller_side - 1
    win_size = max(win_size, 3)
    
    ssim_index, diff = ssim(image1, image2, multichannel=True, full=True, win_size=win_size, channel_axis=2)
    diff = (diff * 255).astype("uint8")
    
    mse_value = mse(image1, image2)
    
    # ssim_index is 'structural similarity index' (https://en.wikipedia.org/wiki/Structural_similarity_index_measure),
    # which is a popular measure of image similarity. Since it only measures gray-scale images, mse_value is also used,
    # which measures 'mean square error' (https://en.wikipedia.org/wiki/Mean_squared_error). Together they should be a
    # robust way to spot image differences without false alarms.
    if ssim_index < ssim_threshold or mse_value > mse_threshold:
        return -1, ssim_index, mse_value, diff
    else:
        return 0, ssim_index, mse_value, None

def main():
    parser = argparse.ArgumentParser(description="Compare two images for similarity.")
    parser.add_argument("--image", required=True, help="Path to the first image.")
    parser.add_argument("--ref", required=True, help="Path to the reference image.")
    parser.add_argument("--ssim-thresh", type=float, default=0.9, help="Threshold for the Structural Similarity Index (SSI).")
    parser.add_argument("--mse-thresh", type=float, default=1000, help="Threshold for the Mean Squared Error (MSE).")
    parser.add_argument("--quiet", action="store_true", help="Suppress output if specified.")
    
    args = parser.parse_args()
    
    result, ssim_index, mse_value, diff = compare_images(args.image, args.ref, args.ssim_thresh, args.mse_thresh)
    
    if not args.quiet:
        print(f"Result: {result}")
        print(f"SSIM Index: {ssim_index:.3f}")
        print(f"MSE Value: {mse_value:.3g}")
    
    if result == -1:
        image_path1_stem, image_path1_ext = os.path.splitext(args.image)
        diff_image_path = f"{image_path1_stem}_diff{image_path1_ext}"
        cv2.imwrite(diff_image_path, diff)
        if not args.quiet:
            print(f"Difference image saved to: {diff_image_path}")

if __name__ == "__main__":
    main()
