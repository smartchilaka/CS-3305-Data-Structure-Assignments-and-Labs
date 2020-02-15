#include "sequence1.h"
#include <cassert>
#include <iostream>

namespace main_savitch_3
{
    sequence::sequence()
   {
       used = 0;
       current_index = 0;
   }
   void sequence::start()
   {
       if (used > 0)
       {
           current_index = 0;
       }
       else
       {
           current_index = used;
       }
      
   }
void sequence::advance()
   {
       if (is_item())
       {
           current_index++;
       }
       else
       {
           std::cout << "NO CURRENT ITEM" << std::endl;
       }
   }
   void sequence::insert(const value_type& entry)
   {
       if (size() < CAPACITY)
       {
           if (!is_item())
           {
               start();
           }

           for (size_t i = used; i > current_index; i--)
           {
               data[i] = data[i-1];
           }

           data[current_index] = entry;

           used++;
          
       }
       else
       {
           std::cout << "ACTION NOT PERFORMED, size() >= CAPACITY!" << std::endl;
       }
   }
   void sequence::attach(const value_type& entry)
   {
       if (size() < CAPACITY)
       {

           if (is_item())
           {
               for (size_t i = used; i > current_index + 1; i--)
               {
                   data[i] = data[i-1];
               }

               data[current_index + 1] = entry;

               current_index++;

               used++;
           }
           else
           {
               data[used] = entry;
               current_index = used;
               used++;
           }

       }
       else
       {
           std::cout << "ACTION NOT PERFORMED, size() >= CAPACITY!" << std::endl;
       }
   }
   void sequence::remove_current()
   {
       if (is_item())
       {

           for (size_t i = current_index; i < used; i++)
           {
               data[i] = data[i+1];
           }

           used--;
       }
       else
       {
           std::cout << "NO CURRENT ITEM" << std::endl;
       }
   }
   sequence::size_type sequence::size() const
   {
       return used;
   }
   bool sequence::is_item() const
   {
       return ((current_index >= 0) && (current_index < used) && (used != 0));
   }
   sequence::value_type sequence::current() const
   {
       if (is_item())
       {
           return data[current_index];
       }
       else
       {
           std::cout << "NO CURRENT ITEM" << std::endl;
       }
   }

}