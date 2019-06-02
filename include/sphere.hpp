// This class contains the representation of a discrete sphere.

class Sphere
{
private:
    unsigned int uSubDiv, vSubDiv;
    float radius;
    float origin[3];
public:
    Sphere();
    ~Sphere();
};