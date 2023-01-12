#include "set.h" 
#include <SFML/Graphics.hpp> 
#include <ctime> 
#include "functions.h"
using namespace sf;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));
    // Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ 
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FPS);
    //Ñîçäàíè èãðîâûõ îáúåêòîâ 
      // Ðàêåòêè 
    RectangleShape bat;
    bat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH));
    bat.setFillColor(BAT_COLOR);
    bat.setPosition((WINDOW_WIDTH - BAT_WIDTH) / 2, WINDOW_HEIGHT - BAT_HEIGTH - BAT_OFFSET);
    bat.setRotation(90); 

    CircleShape ball(BALL_RADIUS);
    ball.setPosition(10, 20);
    ball.setFillColor(BALL_COLOR);

    float arr_speed[]{-5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f,};
            int index = rand() % 10;
            float ball_speedx = arr_speed[index];
            index = rand() % 10;
            float ball_speedy = arr_speed[index];


    // Запуск окна 
    while (window.isOpen())
    {


        // Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå 
        Event event;
        while (window.pollEvent(event))
        {
            // Если пользователь хочет закрыть, то:
            if (event.type == Event::Closed)
                
                // Закрываем окно. 
                window.close();
        }


        // ракетка  
       
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
           bat.move(batDx, 0);
        } 
        else if (Keyboard::isKeyPressed(Keyboard::Left)) {
           bat.move(-batDx, 0);

      }
        
  
   ball.move(ball_speedx, ball_speedy);
   if (ball.getPosition().x <= 0) {
       ball_speedx = -ball_speedx;
 }
   if ((ball.getPosition().x + 2 * BALL_RADIUS) >= WINDOW_WIDTH)
   {
       ball_speedx = -ball_speedx;
}
   if (ball.getPosition().y <= 0) 
   {
       ball_speedy = -ball_speedy;
   }
   // Если мяч касается нижней части окна, то игра закрывается. 
   if (ball.getPosition().y  >= WINDOW_HEIGHT) {
       window.close();
   }

       
       

        //Счёт 
           int Score = 0;
            Font font;
            font.loadFromFile("RodchenkoCTT Regular.ttf");
            Text ScoreText; 
            initText(ScoreText, Score, font, charSize, textstartpos);

            
           
          
            //МЯЧ 
            //вычисляем точки середины сторон описанного вокруг мяча квадрата. 
            float ballX = ball.getPosition().x;
            float ballY = ball.getPosition().y;
            Vector2f midTop{ ballX + BALL_RADIUS, ballY};
            Vector2f midLeft{ ballX, ballY + BALL_RADIUS };
            Vector2f midBottom{ ballX  + 2 * BALL_RADIUS, ballY };
            Vector2f midRight{ ballX + BALL_RADIUS, ballY };
            //Удар об ракетку 
            if (pointInRect(bat, midRight)) {
                ball_speedy = -ball_speedy;
                Score += 1; 
               ScoreText.setString(std::to_string(Score));
            }

            if (pointInRect(bat, midBottom) || pointInRect(bat, midTop)) {
                ball_speedx = -ball_speedx;
                Score += 1; 
                ScoreText.setString(std::to_string(Score));
            } 


            // îòðèñîâêà îáúåêòîâ è îêíà. 
            window.clear();
        window.draw(bat);
        window.draw(ball);
        window.draw(ScoreText);  


        // Îòðèñîâêà îêíà  
        window.display();
    }

    return 0;
}