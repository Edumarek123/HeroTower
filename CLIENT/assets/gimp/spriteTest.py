import pygame
import sys

infos = sys.argv

scale = 20
spriteSize = 32
spritePositionY = int(infos[2])
PATH = str(infos[1])


background_colour = (255, 255, 255)
(width, height) = (spriteSize * scale, spriteSize * scale)
screen = pygame.display.set_mode((width, height))

pygame.display.set_caption('SpriteTester')

pygame.init()
clock = pygame.time.Clock()

#SPRITE
spriteSheet = pygame.image.load(PATH)
maxSpritePositionX = spriteSheet.get_width()/ spriteSize
spriteSheet = pygame.transform.scale(spriteSheet, (width * spriteSheet.get_width() / spriteSize, height * spriteSheet.get_height() / spriteSize))
spritePositionX = 0

running = True
while running:
  screen.fill(background_colour)
  screen.blit(spriteSheet.subsurface(width * spritePositionX, height*spritePositionY, width, height), (0, 0))
  pygame.display.flip()


  spritePositionX += 1
  if(spritePositionX >= maxSpritePositionX):
    spritePositionX = 0


  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False

  clock.tick(6)
