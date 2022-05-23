#include <stdexcept>
#include "OrgChart.hpp"
#include <queue>

using namespace std;

namespace ariel
{

    OrgChart &OrgChart::add_root(string root)
    {
        if (this->head == NULL)
        {
            Node *new_root = new Node;
            new_root->data = root;
            new_root->my_idChild = 0;
            new_root->my_lvl = 0;
            new_root->next = NULL;
            this->highest_lvl = 0;
            new_root->Lower_Lvl_Arr = new vector<Node *>;
            this->head = new_root;
            this->lvls = new vector<Node *>;
            this->lvls->push_back(new_root);
            return *this;
        }
        else
        {
            this->head->data = root;
        }
        return *this;
    }

    Node *OrgChart::DFS_get_bos(string bos, Node *root)
    {
        if (root->data == bos)
        { // for the first time
            return root;
        }
        Node *temp = root;
        for (size_t i = 0; i < temp->Lower_Lvl_Arr->size(); i++)
        {
            if (temp->Lower_Lvl_Arr->at(i)->data == bos)
            {
                return temp->Lower_Lvl_Arr->at(i);
            }
            Node *check_Node = DFS_get_bos(bos, temp->Lower_Lvl_Arr->at(i));
            if (check_Node != NULL)
            {
                return check_Node;
            }
        }

        return NULL;
    }

    OrgChart &OrgChart::add_sub(string bos, string object)
    {
        if (this->head == NULL)
        {
            throw runtime_error("no root");
        }
        Node *temp; // get the node father
        if (!(temp = DFS_get_bos(bos, this->head)))
        {
            throw runtime_error("error,wrong boss name");
        }
        Node *add = new Node;
        add->data = object;
        add->father = temp;
        add->next = NULL;
        add->my_lvl = temp->my_lvl + 1;
        add->Lower_Lvl_Arr = new vector<Node *>;
        add->my_idChild = temp->Lower_Lvl_Arr->size();
        temp->Lower_Lvl_Arr->push_back(add);

        if (this->highest_lvl < add->my_lvl)
        { // if he the first in this lvl
            this->lvls->push_back(add);
        }
        else
        {
            Node *temp2 = this->lvls->at(add->my_lvl);
            while (temp2->next)
            {
                temp2 = temp2->next;
            }
            temp->next = add; // put add in the end
        }

        if (add->my_lvl > this->highest_lvl) // save the highest lvl
        {
            this->highest_lvl = add->my_lvl;
        }

        return *this;
    }
    OrgChart::BFS(vector<Node *> *v, Node *head)
    {
        Node *temp = head;
        if (!head)
        { // if head !=null
            v->push_back(head);
        }
        for (size_t i = 0; i < head->Lower_Lvl_Arr->size(); i++)
        {
        }
    }
   
    string* OrgChart::begin_level_order()
    {
        vector<Node *> *v;
        queue<Node *> q;
        q.push(this->head);
        while (!q.empty)
        {
            Node *temp = q.pop();
            v->push_back(temp); // insert the node to the vector
            for (size_t i = 0; i < count; i++)
            {
                q.push(temp->Lower_Lvl_Arr.at(i));
            }
        }
        vector<string> vs = new vector<string>;
        for (size_t i = 0; i < v->size(); i++)
        {
            vs.push_back(v->at(i)->data);
        }
        vs.push_back("");
        return &(vs.at(0));
    }
    vector<string> OrgChart::end_level_order()
    {
        vector<Node *> *v = new vector<Node>;
        queue<Node *> q;
        q.push(this->head);
        while (!q.empty)
        {
            Node *temp = q.pop();
            v->push_back(temp); // insert the node to the vector
            for (size_t i = 0; i < count; i++)
            {
                q.push(temp->Lower_Lvl_Arr.at(i));
            }
        }
        return v->end();
    }
    vector<string> OrgChart::begin_reverse_order()
    {
        vector<Node *> *v;
        vector<Node *> *t;
        queue<Node *> q;
        q.push(this->head);
        while (!q.empty)
        {
            Node *temp = q.pop();
            v->push_back(temp); // insert the node to the vector
            for (size_t i = 0; i < count; i++)
            {
                q.push(temp->Lower_Lvl_Arr.at(i));
            }
        }

        for (size_t i = 0; i < v->size(); i++)
        {
            t->push_back(v->pop_back());
        }
        vector<string> vs = new vector<string>;
        for (size_t i = 0; i < v->size(); i++)
        {
            vs.push_back(v->at(i)->data);
        }
        return vs;
    }
    vector<string> OrgChart::reverse_order()
    {
        vector<Node *> *v;
        vector<Node *> *t;
        queue<Node *> q;
        q.push(this->head);
        while (!q.empty)
        {
            Node *temp = q.pop();
            v->push_back(temp); // insert the node to the vector
            for (size_t i = 0; i < count; i++)
            {
                q.push(temp->Lower_Lvl_Arr.at(i));
            }
        }

        for (size_t i = 0; i < v->size(); i++)
        {
            t->push_back(v->pop_back());
        }
        vector<string> vs = new vector<string>;
        for (size_t i = 0; i < v->size(); i++)
        {
            vs.push_back(v->at(i)->data);
        }
        return vs;
    }
    vector<string> OrgChart::begin_preorder()
    {
        vector<Node *> v = new vector<Node *>;
        v->push_back(this->head);
        DFS(v, this->head); // we fill v;

        vector<string> vs = new vector<string>;
        for (size_t i = 0; i < v->size(); i++)
        {
            vs.push_back(v->at(i)->data);
        }
        delete(v);
        return vs;
    }
    vector<string> OrgChart::end_preorder()
    {
        vector<Node *> v = new vector<Node *>;
        v->push_back(this->head);
        DPS(v, this->head); // we fill v;
        return v.end();
    }
    ostream &operator<<(ostream &output, OrgChart &org)
    {
        for (iterator it = org.begin_level_order(); it != org.end_level_order(); ++it)
        {
            Node *temp = it.pitr;
            output << "boss-" << temp->data << " : his workers - ";
            // print them and the sons
            for (size_t i = 0; i < temp->Lower_Lvl_Arr->size(); i++)
            {
                if (i == temp->Lower_Lvl_Arr->size() - 1)
                {
                    output << temp->Lower_Lvl_Arr->at(i)->data << ".";
                }
                else
                {
                    output << temp->Lower_Lvl_Arr->at(i)->data << " , ";
                }
            }
            output << "\n";
        }

        return output;
    }
    iterator OrgChart::begin()
    {
        vector<Node *> *v = new vector<Node>;
        queue<Node *> q;
        q.push(this->head);
        while (!q.empty)
        {
            Node *temp = q.pop();
            v->push_back(temp); // insert the node to the vector
            for (size_t i = 0; i < count; i++)
            {
                q.push(temp->Lower_Lvl_Arr.at(i));
            }
        }
        return v->begin();
    }
    OrgChart::Iterator OrgChart::end()
    {
        vector<Node *> *v = new vector<Node>;
        queue<Node *> q;
        q.push(this->head);
        while (!q.empty)
        {
            Node *temp = q.pop();
            v->push_back(temp); // insert the node to the vector
            for (size_t i = 0; i < count; i++)
            {
                q.push(temp->Lower_Lvl_Arr.at(i));
            }
        }
        return v->end();
    }

    string *OrgChart operator->()
    {
        if (this->pitr == NULL)
        {
            throw runtime_error("error , cant print from null object");
        }
        return &(this->pitr->data); // need to check if null
    }
    string OrgChart::Iterator::operator*()
    {
        if (this->pitr == NULL)
        {
            throw runtime_error("error , cant print from null object");
        }
        return this->pitr->data;
    }
    OrgChart::~OrgChart(){

    };
}