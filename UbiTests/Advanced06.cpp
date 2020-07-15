/*  C++ Advanced 6

    The method Entity::PerceptSurroundings() runs an order of magnitude slower than it should.
    Fix the performance problems.
*/

#include <iostream>
#include <vector>
#include <random>

template <typename T> inline T sqr(T a)
{
    return a * a;
}

class Entity
{
public:
    static const float PERCEPTION_RANGE;
    Entity(float x, float y, float z, bool perceptible, bool blind)
        :m_x(x), m_y(y), m_z(z), m_perceptible(perceptible), m_blind(blind) {}

    float DistanceTo(Entity& other);
    void PerceptSurroundings(std::vector<Entity*> allObjects);

    std::vector<Entity*>& GetPerceptedObjects() { return m_perceptedObjects; }
private:
    float m_x, m_y, m_z;
    bool m_perceptible;
    bool m_blind;

    std::vector<Entity*> m_perceptedObjects;
};

const float Entity::PERCEPTION_RANGE = 20.0f;

float Entity::DistanceTo(Entity& other)
{
    return sqr(m_x - other.m_x) + sqr(m_y - other.m_y) + sqr(m_z - other.m_z);
}

void Entity::PerceptSurroundings(std::vector<Entity*> allObjects)
{
    m_perceptedObjects.clear();
    if (!m_blind)
    {
        for (unsigned i = 0; i < allObjects.size(); ++i)
        {
            Entity objectToCheck = *allObjects[i];
            if (objectToCheck.m_perceptible && DistanceTo(objectToCheck) < sqr(PERCEPTION_RANGE))
            {
                m_perceptedObjects.push_back(allObjects[i]);
            }
        }
    }
}

void main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> randBool(0, 1);
    std::uniform_real_distribution<float> randCoord(-20.0f, 20.0f);

    std::vector<Entity*> objects;
    for (int i = 0; i < 50; ++i)
        objects.push_back(new Entity(randCoord(rng), randCoord(rng), randCoord(rng), randBool(rng) != 0, randBool(rng) != 0));

    Entity player(10.f, 10.f, 10.f, true, false);

    for (int i = 0; i < 100000; ++i)
        player.PerceptSurroundings(objects);

    std::cout << "Number of objects the player can see: " << player.GetPerceptedObjects().size() << std::endl;
}

