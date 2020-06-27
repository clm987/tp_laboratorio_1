#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "IOdata.h"
#include "articulo.h"
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

//////////////////////////////////////////////
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(this));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    	return this;
    }

    return this;
}

///////////////////////////////////////////////////
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->size !=0)
    	{
    		returnAux = this->size;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

 return returnAux;
}

////////////////////////////////////////////////////////////
static Node* getNode(LinkedList* this, int nodeIndex)
{
	 Node* pNode = NULL;
	    int i;
	    if(this != NULL && ll_len(this) > 0 && nodeIndex < ll_len(this) && nodeIndex >= 0)
	    {
	        pNode = this->pFirstNode;
	        for(i=0;i< nodeIndex;i++)
	        {
	            pNode = pNode -> pNextNode;
	        }
	    }
	    return pNode;
}


/////////////////////////////////////////////////////////////////////
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
  	int returnAux = -1;
  	Node* newNode;
    Node* otherNode;

    if(this != NULL && nodeIndex <= ll_len(this) && nodeIndex >= 0)
    {
    	newNode = (Node*) malloc(sizeof(Node));

    	if(newNode != NULL)
    	{
    		if(nodeIndex == 0)
    		{
    			newNode->pNextNode = this->pFirstNode;
    			this->pFirstNode = newNode;
    			newNode->pElement = pElement;
    			this->size++;
    			returnAux = 0;
    		}
    		else
    		{
    			otherNode = getNode(this, (nodeIndex -1));
    			newNode->pNextNode = otherNode->pNextNode;
    			otherNode->pNextNode = newNode;
    			newNode->pElement = pElement;
    			this->size++;
    			returnAux = 0;
    		}
    	}
    }
   return returnAux;
}

////////////////////////////////////////////////////
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
    int length;

    if(this != NULL)
    {
    	length = ll_len(this);

    	if(length == 0)
    	{
    		addNode(this,0,pElement);
    		returnAux = 0;
    	}
    	else
    	{
    		addNode(this,(length),pElement);
    		returnAux = 0;
    	}
    }
    return returnAux;
}

///////////////////////////////////////////////////
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
    Node* thisNode = NULL;
    int length;

    if(this != NULL)
    {
    	length = ll_len(this);

    	if(index < length && index >= 0)
    	{
    		thisNode = getNode(this,index);
    		if(thisNode != NULL)
    		{
    			returnAux = thisNode->pElement;
    		}
    	}
    }
    return returnAux;
}


///////////////////////////////////////////////////////
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* thisNode = NULL;
    int length;

      if(this != NULL)
      {
      	length = ll_len(this);

      	if(index < length && index >= 0)
      	{
      		thisNode = getNode(this,index);
      		if(thisNode != NULL)
      		{
      			thisNode->pElement = pElement;
      			returnAux = 0;
      		}
      	}
      }

    return returnAux;
}


//////////////////////////////////////////////
int ll_remove(LinkedList* this,int index)
{
	 int returnAux = -1;
	    Node* auxNode = getNode(this,index);
	    if(this != NULL && index >= 0 && index < ll_len(this))
	    {
	        if(index == 0)
	        {
	            this->pFirstNode = auxNode->pNextNode;
	            free(auxNode);
	            this->size = ll_len(this) - 1;
	            returnAux = 0;
	        }
	        else if(index > 0)
	        {
	            Node* previousNode = getNode(this,index - 1);
	            previousNode->pNextNode = auxNode->pNextNode;
	            free(auxNode);
	            this->size = ll_len(this) - 1;
	            returnAux = 0;
	        }
	    }

    return returnAux;
}


/////////////////////////////////////////
int ll_clear(LinkedList* this)
{
	int returnAux = -1;
	  int i = 0;
	    int len = ll_len(this);
	    if(this != NULL)
	    {
	        for(i = 0;i < len;i++)
	        {
	            ll_remove(this,i);
	        }
	        returnAux = 0;
	    }
   return returnAux;
}


/////////////////////////////////////////////////////
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int length;

    if(this != NULL)
    {

    	length = ll_len(this);

    	if(length > 0)
    	{
    		ll_clear(this);
    		free(this);
    		returnAux = 0;
    	}else if(length == 0)
    	{
    		ll_clear(this);
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

//////////////////////////////////////////////////
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int length;
    int i;
    Node* thisNode = NULL;
    void* auxElement;

    if(this != NULL)
    {
    	length = ll_len(this);

    	for(i=0; i<length; i++)
    	{
    		thisNode = getNode(this,i);
    		auxElement = thisNode->pElement;

    		if(auxElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

///////////////////////////////////////////////////
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int length;

    if(this != NULL)
    {
    	length = ll_len(this);
    	if(length == 0)
    	{
    		returnAux = 1;
    	}else if(length > 0)
    	{
    		returnAux  = 0;
    	}
    }
    return returnAux;
}

/////////////////////////////////////////////////////////////
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int length;

    if(this != NULL && index >=0)
    {
    	length = ll_len(this);

    	if(index<=length)
    	{
    		addNode(this,index,pElement);
    		returnAux = 0;
    	}

    }
    return returnAux;
}


//////////////////////////////////////////////////
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int length;
    Node* thisNode;

    if(this != NULL)
    {
    	length = ll_len(this);

    	if(index < length && index >= 0)
    	{
    		thisNode = getNode(this,index);
    		returnAux = thisNode->pElement;
    		ll_remove(this,index);
    	}
    }
    return returnAux;
}


/////////////////////////////////////////////////////////
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = ll_indexOf(this,pElement);
    	if(returnAux != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}

    }
    return returnAux;
}

/////////////////////////////////////////////////////////////
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int length0;
    int length1;
    int i;
    int matchCount = 0;
    Node* thisNode0;
    Node* thisNode1;
    void* auxElement0;
    void* auxElement1;

    if(this != NULL && this2 != NULL)
    {
    	length0 = ll_len(this);
    	length1 = ll_len(this2);

    	if(length0 == length1)
    	{
    		for(i=0; i<length1; i++)
    		{
    			thisNode0 = getNode(this,i);
    			thisNode1 = getNode(this,i);

    			auxElement0 = thisNode0->pElement;
    			auxElement1 = thisNode1->pElement;

    			if(auxElement0 == auxElement1)
    			{
    				matchCount++;
    			}
    		}
    		if(matchCount == length0)
    		{
    			returnAux = 1;
    		}
    		else
    		{
    			returnAux = 0;
    		}
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

////////////////////////////////////////////////////////////
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int length;
    int i;
    void* auxElement;

    if(this != NULL)
    {
    	length = ll_len(this);
    	if(from >= 0 && from <length && to >= 0 && to <= length && from <= to && length >= 0)
    	{
    		cloneArray = ll_newLinkedList();
    		if(cloneArray != NULL)
    		{
				for(i=from; i<=to; i++)
				{
					auxElement = ll_get(this,i);
					ll_add(cloneArray,auxElement);
				}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int length;
    int i;
    void* auxElement;

     if(this != NULL)
     {
     	length = ll_len(this);
     	if(length >= 0)
     	{
     		cloneArray = ll_newLinkedList();
     		if(cloneArray != NULL)
     		{
 				for(i=0; i<length; i++)
 				{
 					auxElement = ll_get(this,i);
 					ll_add(cloneArray,auxElement);
 				}
     		}
     	}
     }

    return cloneArray;
}


///////////////////////////////////////////////////////////////////////
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retCode =-1;
    int length;
    int flagSort;
    int i;
    void* pElement0;
    void* pElement1;
    void* auxElement;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	length = ll_len(this);

    	if(length > 0)
    	{
    		 do
    		{
				flagSort = 0;
					for(i=0; i<length-1; i++)
					{
						pElement0 = ll_get(this,i);
						pElement1 = ll_get(this,(i+1));

						if((pFunc(pElement0,pElement1)==1 && order == 1)||(pFunc(pElement0,pElement1)==-1 && order == 0))
						{
							auxElement = pElement0;
							ll_set(this,i,pElement1);
							ll_set(this,i+1,auxElement);
							flagSort = 1;
						}
					}
					retCode = 0;
    		}while(flagSort);
    	}
    }
    return retCode;
}
////////////////////////////////////////////////////////////////////
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int retCode = -1;
	int length;
	int i;
	void* auxElement;
	int total = 0;

	if(this != NULL && fn != NULL)
	{
		length = ll_len(this);
		for(i=0; i<length; i++)
		{
			auxElement = ll_get(this,i);
			if(auxElement != NULL)
			{
				total += fn(auxElement);
			}
		}
	retCode = total;
	}
	return retCode;
}
///////////////////////////////////////////////////////////////////
LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
		int length;
		int i;
		void* auxElement;

		if(this != NULL && fn != NULL)
		{
			length = ll_len(this);
			for(i=0; i<length; i++)
			{
				auxElement = ll_get(this,i);
				if(auxElement != NULL)
				{
					fn(auxElement);
				}
			}
			return this;
		}
	return NULL;
}
