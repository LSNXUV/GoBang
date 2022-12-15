
#include "Record.h"


class Records
{

    private:
        /* data */
    public:
        Record *Head,*End;
        int Count;

        bool AddRecords(Record *record);

        Record TopRecords();

        bool RemoveRecords(int id);

        
        Records(/* args */);
        ~Records();

};


Records::Records()
{
    Head = new Record;
    Head->next = NULL;
    End = Head;
    Count = 0;
}

Records::~Records(){

}






bool Records::AddRecords(Record *record)
{
    Count++;
    record->EndTime = record->CreateTime();
    End->next = record;
    record->next = NULL;
    End = record;
    return true;
}

bool Records::RemoveRecords(int id)
{
    if(!Count) return false;

    Record *head = Head;
    int i = 1;
    while(head->next && i++ != id) ;
    if(!head) return false;
    Record *s = head->next;
    head->next = s->next;
    free(s);
    return true;
}

Record Records::TopRecords()
{
    return *End;
}
