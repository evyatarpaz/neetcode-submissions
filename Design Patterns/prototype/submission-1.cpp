class Shape {
public:
    virtual ~Shape() {}
    virtual Shape* clone() const = 0;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    Shape* clone() const override {
        return new Rectangle(getWidth(),getHeight());
    }
};

class Square : public Shape {
private:
    int length;

public:
    Square(int l) : length(l) {}

    int getLength() const {
        return length;
    }

    Shape* clone() const override {
        return new Square(getLength());
    }
};

class Test {
public:
    vector<Shape*> cloneShapes(const vector<Shape*>& shapes) {
        vector<Shape*> l;
        for(const Shape* shape : shapes){
            l.emplace_back(shape->clone());
        }
        return l;
    }
};
