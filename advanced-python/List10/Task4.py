# Wiem, że raczej nie o taką implementację chodziło w tym zadaniu, 
# ale tyle mogłam wymysleć żeby to wyglądało ładnie

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.image import imread
from matplotlib.animation import FuncAnimation

image = imread('image.png')

def weselsza_modyfikacja(image):
    modified_image = np.copy(image)  
    
    for i in range(len(modified_image)):
        for j in range(len(modified_image[i])):
            pixel = modified_image[i][j]

            sorted_indices = np.argsort(pixel)

            # Zwiększenie największej wartości o +0.2
            pixel[sorted_indices[2]] = min(1.0, pixel[sorted_indices[2]] + 0.2)
            # Zmniejszenie drugiej największej wartości o -0.1
            pixel[sorted_indices[1]] = max(0.0, pixel[sorted_indices[1]] - 0.1)
            # Zmniejszenie najmniejszej wartości o -0.05
            pixel[sorted_indices[0]] = max(0.0, pixel[sorted_indices[0]] - 0.05)

            modified_image[i][j] = pixel

    return modified_image

def smutna_modyfikacja(image):
    modified_image = np.copy(image)  
    
    for i in range(len(modified_image)):
        for j in range(len(modified_image[i])):
            pixel = modified_image[i][j]
            srednia = (pixel[0]+pixel[1]+pixel[2]) / 3
            pixel[0]=pixel[1]=pixel[2]=srednia

            modified_image[i][j] = pixel

    return modified_image

fig, (axs1, axs2, axs3) = plt.subplots(1, 3, figsize=(10, 5))

axs1.imshow(image)
axs1.set_title('Obraz pierwotny')

modified_image = weselsza_modyfikacja(image)
modified_image2 = smutna_modyfikacja(image)

def update(frame):
    alpha = frame / 7.0
    combined_image = (1 - alpha) * image + alpha * modified_image
    combined_image2 = (1 - alpha) * image + alpha * modified_image2

    axs2.imshow(combined_image)
    axs2.set_title('Przejście do obrazu wesolego')

    axs3.imshow(combined_image2)
    axs3.set_title('Przejście do obrazu smutnego')

ani = FuncAnimation(fig, update, frames=7, interval=15)
plt.tight_layout()
plt.show()

# Wyświetlenie obrazów bez animacji:

# fig, (axs1, axs2, axs3) = plt.subplots(1, 3, figsize=(15, 5))

# axs1.imshow(image)
# axs1.set_title('Obraz pierwotny')

# modified_image = weselsza_modyfikacja(image)

# axs2.imshow(modified_image)
# axs2.set_title('Obraz wesoly')

# modified_image2 = smutna_modyfikacja(image)

# axs3.imshow(modified_image2)
# axs3.set_title('Obraz smutny')

# plt.tight_layout()
# plt.show()