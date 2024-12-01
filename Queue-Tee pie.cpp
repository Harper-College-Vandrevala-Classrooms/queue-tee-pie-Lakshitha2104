#include <iostream>
#include <string>
using namespace std;

class Cutie {
public:
    virtual string description() = 0;      
    virtual int cuteness_rating() = 0;    
    virtual ~Cutie() = default;           
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes.";
    }

    int cuteness_rating() override {
        return 11;
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A playful kitten with soft fur.";
    }

    int cuteness_rating() override {
        return 10;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny monkey with a curious expression.";
    }

    int cuteness_rating() override {
        return 9;
    }
};

class QueueTees {
private:
    Cutie* queue[10]; 
    int front;        
    int rear;         
    int count;        
    int max_size;     

public:
    QueueTees() : front(0), rear(0), count(0), max_size(10) {}

    void enqueue(Cutie& cutie) {
        if (count == max_size) {
            cout << "The queue is full. Cannot enqueue any more items.\n";
            return;
        }
        queue[rear] = &cutie;
        rear = (rear + 1) % max_size; // Circular increment
        count++;
    }

    Cutie* dequeue() {
        if (count == 0) {
            cout << "The queue is empty. Cannot dequeue any items.\n";
            return nullptr;
        }
        Cutie* cutie = queue[front];
        front = (front + 1) % max_size; // Circular increment
        count--;
        return cutie;
    }

    int size() {
        return count;
    }
};

int main() {
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    QueueTees queue;

    cout << "Initial queue size: " << queue.size() << "\n";

    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    cout << "Queue size after enqueuing: " << queue.size() << "\n";

    for (int i = 0; i < 3; i++) {
        Cutie* cutie = queue.dequeue();
        if (cutie) {
            cout << "Dequeued: " << cutie->description() << " (Cuteness rating: " 
                 << cutie->cuteness_rating() << ")\n";
        }
    }

    cout << "Final queue size: " << queue.size() << "\n";

    return 0;
}
