import pygame
import time
import random
pygame.font.init()

WIDTH=1000
HEIGHT=700

PLAYER_WIDTH=40
PLAYER_HEIGHT=50

STAR_WIDTH = 10
STAR_HEIGHT= 20


PLAYER_VELx=10
PLAYER_VELy=10

STAR_VEL= 5###



CLOCK_TICKTIME =  60 ## MAX NO OF TIMES U want ur while loop to run in  1SEC


FONT = pygame.font.SysFont("comicsans",30)



WIN=pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption(" space doge")


BG = pygame.image.load("bg (1).jpeg")


### draw fun start here
def draw(player,escaped_time,stars):
    WIN.blit(BG,(0,0))#top-left coordinate of backgroung image
    
    time_text = FONT.render(f"Time:{round(escaped_time)}s",1,"white")##  color u want ur text to be
    WIN.blit(time_text,(10,10))
    
    pygame.draw.rect(WIN, (32,132,135),player)# u can wwrite in RGB also
    
    for star in stars:
        pygame.draw.rect(WIN,"white",star)
    pygame.display.update()
## draw fun ends here



    ## main fun start here
def main():
    run = True
    player = pygame.Rect(200,HEIGHT - PLAYER_HEIGHT,PLAYER_WIDTH,PLAYER_HEIGHT)
    
    clock=pygame.time.Clock()##
    start_time = time.time()
    escaped_time=0
    
    star_add_increment=2000
    star_count=0
    
    stars=[]
    hit= False
    
    
    while run:
        star_count+=clock.tick(CLOCK_TICKTIME)## no of milisec since last clock ticked
        escaped_time = time.time() - start_time
        
        
        
        if star_count> star_add_increment:
            for i in range(3):
               star_x = random.randint(0, WIDTH - STAR_WIDTH)## x coordinate of our star
               star = pygame.Rect(star_x,-STAR_HEIGHT,STAR_WIDTH,STAR_HEIGHT)## y coordinte of where star begins = -20 (above the screen)
               stars.append(star)## star -- array
            
            
            star_add_increment -= 50 ##  creating faster stars as game continues
            star_add_increment = max(200, star_add_increment)##   setting a max bar of how quickly stars will be produced
            star_count=0## 
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
               run = False
               break
        keys = pygame.key.get_pressed()
        
        if keys[pygame.K_LEFT]:
            player.x -=PLAYER_VELx## player.x = x cordinate of player
        if keys[pygame.K_RIGHT]:
            player.x+= PLAYER_VELx
        if keys[pygame.K_UP]:
            player.y-=PLAYER_VELy## player.x = x cordinate of player
        if keys[pygame.K_DOWN]:
            player.y+= PLAYER_VELy
        
        for star in stars[:]:
            star.y+= STAR_VEL
            if star.y>HEIGHT:
             stars.remove(star)##  the star which reaced bottom of console ...remove from the STARS array
            elif star.y + star.height >= player.y and star.colliderect(player):## if player succesfully passed the star ... then remove the star
                stars.remove(star)
                hit = True
                break
        
       
       ## star.y = star.y% HEIGHT    
        player.x = player.x%WIDTH
        player.y = player.y%HEIGHT
        if hit:
            lost_text=FONT.render("You lost!",1,"white")
            WIN.blit(lost_text,(WIDTH/2 - lost_text.get_width()/2,HEIGHT/2 - lost_text.get_height()/2))## lost signal in middle
            pygame.display.update()
            pygame.time.delay(4000)## show 4000 milisec the lost message
            break
        draw(player,escaped_time,stars)   
        
        
    pygame.quit()     
    
## main fun ends here
    
##if __name__==" __main__":
main()
