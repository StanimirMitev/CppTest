/*  C++ Basics 12
    
    You are working on a Space Simulator game. For some reason, ships in your game are sometimes failing to die (but sometimes they work). 
    Debugging has shown that the Ship::GetHit method is properly called with the proper damage. 

    Fix the problems in the class below.
*/

class Ship
{
    Ship() : m_IsAlive(true) {}

    void OnHit(unsigned damage)
    {
        m_Health -= damage;
        if (m_Health <= 0)
        {
            OnDestroyed();
        }
    }

    void OnDestroyed()
    {
        m_IsAlive = false;
    }	

private:
    bool m_IsAlive;
    //when damaged is greater than m_health there is an underflow error with unsigned, 
    int m_Health;
};

void main(int argc, char* argv[])
{

}


