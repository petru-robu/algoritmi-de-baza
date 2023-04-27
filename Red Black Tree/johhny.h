#include <iostream>
#include <time.h>
#include <stdlib.h>


enum colors {RED, BLACK};

template<class T>struct Node
{
    T data;
    bool color;
    Node<T> *left, *right, *parent;

    Node(T);
    Node<T>* getSibling();
    ~Node();
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this-> parent = nullptr;
    this->color = RED;
}

template <class T>
Node<T>::~Node()
{

}

template< class T >
Node<T>* Node<T>::getSibling()
{
    if (parent == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (parent -> left == this)
        {
            return this -> parent -> right;
        }
        else
        {
            return this -> parent -> left;
        };
    }
}


template <class T> class RBTree
{

private:
    Node<T> *root;

public:
    RBTree()
    {
        root = nullptr;
    }
    ~RBTree()
    {
        delete(root);
    }

    Node<T>* getRoot()
    {
        return root;
    }

    void insert (T x)
    {
        if (root == nullptr)
        {
            root = new Node<T>(x);
            root-> parent = nullptr;
            root->color = BLACK;
        }
        else
        {
            auto tmp = getRoot();
            while (tmp != nullptr)
            {
                if (tmp-> data > x)
                {
                    if (tmp -> left == nullptr)
                    {
                        tmp -> left = new Node <T> (x);
                        tmp -> left -> parent = tmp;
                        tmp = tmp->left;
                        break;
                    }
                    else
                    {
                        tmp = tmp->left;
                    }
                }
                else
                {
                    if (tmp -> right == nullptr)
                    {
                        tmp -> right = new Node <T>(x);
                        tmp -> right -> parent = tmp;
                        tmp = tmp -> right;
                        break;
                    }
                    else
                    {
                        tmp = tmp -> right;
                    }
                }
            }
            resolveViolation(tmp);
        }
    }

    void rotateRight(Node <T> *&tmp)
    {

        Node <T> *left = tmp -> left;
        tmp -> left = left -> right;

        if (tmp -> left != nullptr)
        {
            tmp -> left -> parent = tmp;
        }
        left -> parent = tmp -> parent;

        if (tmp -> parent == nullptr)
        {
            tmp = left;
        }
        else if (tmp -> parent -> left == tmp)
        {
            tmp -> parent -> left = left;
        }
        else
        {
            tmp -> parent -> right = left;
        }
        left -> right = tmp;
        tmp -> parent = left;
    }

    void rotateLeft(Node <T> *&tmp)
    {

        Node <T> *right = tmp -> right;


        tmp -> right =  right -> left;
        if (tmp -> right != nullptr)
        {
            tmp -> right -> parent = tmp;
        }

        right -> parent = tmp -> parent;
        if (tmp -> parent == nullptr)
        {
            root = right;
        }
        else if (tmp == tmp -> parent -> left)
        {
            tmp-> parent -> left = right;
        }
        else
        {
            tmp -> parent -> right = right;
        }
        right -> left = tmp;
        tmp->parent = right;
    }

    void resolveViolation(Node<T> *&tmp)
    {
        while (tmp -> color == RED && tmp -> parent != nullptr && tmp -> parent->color == RED)
        {
            Node <T> *parent = tmp -> parent;
            Node <T> *grandparent = parent -> parent;

            if (grandparent != nullptr && grandparent-> left == parent)
            {
                Node <T> *uncle = grandparent -> right;

                if (uncle != nullptr && uncle->color == RED)
                {
                    parent -> color = BLACK;
                    uncle -> color = BLACK;
                    grandparent -> color = RED;
                    tmp = grandpare
nt;
                }
                else
                {
                    if (tmp == parent->right)
                    {
                        rotateLeft(parent);
                        tmp = parent;
                        parent = tmp -> parent;
                    }

                    rotateRight(grandparent);
                    std::swap(parent->color, grandparent->color);
                    tmp = grandparent;
                }
            }
            else
            {
                Node <T> *uncle = grandparent -> left;

                if (uncle != nullptr && uncle->color == RED)
                {
                    parent -> color = BLACK;
                    uncle -> color = BLACK;
                    grandparent -> color = RED;
                    tmp = grandparent;
                }
                else
                {
                    if (tmp == parent -> left)
                    {
                        rotateRight(parent);
                        tmp = parent;
                        parent = tmp -> parent;
                    }

                    rotateLeft(grandparent);
                    std::swap(parent -> color, grandparent -> color);
                    tmp = parent;
                    break;
                }
            }
        }

        root -> color = BLACK;
    }

    Node <T> * find(T data)
    {
        auto tmp = getRoot();
        if (tmp == nullptr)
        {
            return nullptr;
        }

        while(tmp)
        {
            if (tmp -> data == data)
            {
                return tmp;
            }
            else if (data < tmp -> data)
            {
                tmp = tmp -> left;
            }
            else
            {
                tmp = tmp -> right;
            }
        }
        return nullptr;
    }

    Node <T>* nextNode(Node<T> *node)
    {
        auto tmp = node;
        while (tmp -> left != nullptr)
        {
            tmp = tmp -> left;
        };
        return tmp;
    }

    Node <T>* findSuccesor(Node <T> *node)
    {
        if (node -> left != nullptr && node -> right != nullptr)
        {
            return nextNode(node -> right);
        }

        if (node -> left == nullptr && node -> right == nullptr)
        {
            return nullptr;
        }

        if (node -> left == nullptr)
        {
            return node -> right;
        }
        else
        {
            return node -> left;
        }

    }

    void remove(T data)
    {
        auto tmp = find(data);
        auto replace = findSuccesor(tmp);
        if (tmp == nullptr)
        {
            std::cout << "Nodul nu exista" << '\n';
            return;
        }
        else
        {
            if (replace == nullptr)
            {
                if (tmp == root)
                {
                    root = nullptr;
                }
                else
                {
                    if ((replace == nullptr || replace -> color == BLACK) && (tmp -> color == BLACK))
                    {
                        fixDoubleBlack(tmp);
                    }
                    else
                    {
                        std::cout<<tmp -> getSibling() -> data<<"\n";
                        if (tmp -> getSibling() != nullptr)
                        {
                            tmp -> getSibling() -> color = RED;
                        }
                    }
                    if (tmp == tmp -> parent -> left)
                    {
                        tmp -> parent -> left = nullptr;
                    }
                    else
                    {
                        tmp -> parent -> right = nullptr;
                    }
                }
                delete tmp;
                return;
            }

            if (tmp -> left == nullptr || tmp -> right == nullptr)
            {
                if (tmp == root)
                {
                    tmp -> data = replace -> data;
                    tmp -> left = tmp -> right = nullptr;
                    delete replace;
                }

      else
                {
                    if (tmp == tmp -> parent -> left)
                    {
                        tmp -> parent -> left = replace;
                    }
                    else
                    {
                        tmp -> parent -> right = replace;
                    }

                    replace -> parent = tmp -> parent;
                    delete tmp;

                    if (replace != nullptr && replace -> color == BLACK)
                    {
                        fixDoubleBlack(replace);
                    }
                    else
                    {
                        replace -> color = BLACK;
                    }
                }
                return ;
            }
        }
        std::swap(tmp,replace);
        remove(replace -> data);
    }
    void fixDoubleBlack(Node <T> * node)
    {
        auto sibling = node -> getSibling();
        auto parent = node -> parent;
        if (node == root)
        {
            return;
        }

        if (sibling == nullptr)
        {
            fixDoubleBlack(parent);
        }
        else
        {
            if (sibling -> color == RED)
            {
                parent -> color = RED;
                sibling -> color = BLACK;
                if (sibling == parent -> left)
                {
                    rotateRight(parent);
                }
                else
                {
                    rotateLeft(parent);
                }
                fixDoubleBlack(node);
            }
            else
            {
                auto leftChild = sibling -> left;
                auto rightChild = sibling -> right;
                if ((leftChild != nullptr && leftChild->color == RED) || (rightChild != nullptr && rightChild -> color == RED))
                {
                    if (leftChild != nullptr && leftChild -> color == RED)
                    {
                        if (sibling == sibling -> parent -> left)
                        {
                            leftChild -> color = sibling -> color;
                            sibling -> color = parent -> color;
                            rotateRight(parent);
                        }
                        else
                        {
                            leftChild -> color = parent -> color;
                            rotateRight(sibling);
                            rotateLeft(parent);
                        }
                    }
                    else
                    {
                        if (sibling == sibling -> parent -> left)
                        {
                            rightChild -> color = parent -> color;
                            rotateLeft(sibling);
                            rotateRight(parent);
                        }
                        else
                        {
                            rightChild-> color = sibling -> color;
                            sibling -> color = parent -> color;
                            rotateLeft(parent);
                        }
                    }
                    parent -> color = BLACK;
                }
                else
                {
                    sibling -> color = RED;
                    if (parent-> color == BLACK)
                    {
                        fixDoubleBlack(parent);
                    }
                    else
                    {
                        parent -> color = BLACK;
                    }
                }
            }
        }
    }
    void inOrdertraversal(Node <T> * tmp)
    {
        if (tmp == nullptr)
        {
            return;
        }
        if (tmp -> left)
        {
            inOrdertraversal(tmp->left);
        }
        std::cout<<"Nodul "<<tmp -> data << "are culoarea" << tmp -> color<<"\n";
        if (tmp -> parent != nullptr)
        {
            std::cout << "si are parintele " << tmp -> parent -> data<<'\n';
        }
        if (tmp -> left)
        {
            std::cout << "Fiu stang "<<tmp ->left-> data<< '\n';
        }

        if (tmp -> right)
        {
            std::cout << "Fiu drept " <<tmp->right-> data<< '\n';
        }

        if (tmp -> right)
        {
            inOrdertraversal(tmp->right);
        }
    }
};
