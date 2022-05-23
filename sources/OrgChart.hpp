#include <iostream>
#include <string>
#include "Node.hpp"
using namespace std;

namespace ariel
{

    class OrgChart
    {

    public:
        Node *head;
        OrgChart &add_root(const string &root);
        OrgChart &add_sub(const string& bos, string object);
        vector<Node*> *lvls;
        size_t highest_lvl;

        OrgChart()
        {            
            this->head = NULL;
        }

        class Iterator
        {

        private:
            

        public:
            // Node *pitr;
            vector<Node*>* v_it;
            // OrgChart *this_one;
            Node* end_NULL;
            size_t index;

            Iterator(vector<Node*>* v)
            {   this->v_it=v;
                // this->pitr = NULL;
                this->end_NULL=NULL;
                this->index=0;
            }
            Iterator(){
                this->end_NULL=NULL;
                this->v_it=NULL;
               this->index=0;
            }
            ~Iterator();
            Iterator &operator++();
            bool operator!=(const Iterator &other) const;
            bool operator==(const Iterator &other) const;
            string *operator->()const;
            string operator*()const;
        };
        void DFS(vector<Node *> *v, Node *head)const;
        Iterator end()const;
        Iterator begin()const;
        Iterator end_level_order()const;
        Iterator begin_reverse_order()const;
        Iterator begin_level_order()const;
        Iterator reverse_order()const;
        Iterator begin_preorder()const;
        Iterator end_preorder()const;
        ~OrgChart();

    private:
        Node *DFS_get_bos(const string& bos, Node *root);
        friend ostream &operator<<(ostream &output, OrgChart &org);
    };

}