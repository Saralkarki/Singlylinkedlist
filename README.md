# Singly linked list

#### It has taken me a while to understand singly linked list, but as I write this post, I feel I have a better understanding of linked list than I did a week or two before. To be honest, I felt I had somewhat cracked the mysteries of a linked list a two weeks ago, but then I was too lazy to write this post, and I feel at this current moment (as I am scribbling), I am not as comfortable with the concept of the linked list. However, I want to test this out for myself and I am taking the time(or rather pushing myself) to write this post on the linked list.
A caveat, to begin with, I am a beginner programmer so this post might contain numerous programming approaches that might seem absolutely ludicrous. If such is the case, please feel free to comment, and please give me feedback on how I could have approached the problem better( a bit kindly please). With that said, let me dive into the singly linked list.
I went about in understanding the linked list with C. The reason behind picking C as the programming language was- whilst I was learning about linked list, I also wanted to have a better understanding about the concept of pointers.

What is a Singly linked list?
>> In the simplest of words, a singly linked list is a type of data structure. The data in a single list are stored in individual nodes and these nodes are connected via a pointer. Pictorially it can be imagined as a chain.
where each node contains a data type and a pointer(next) which is pointing to the next node. 

What is a node?    
>> Node is a generic way of defining the individual data structure. A node has two elements, a data type and a pointer. 

In C this can be defined by a struct
```
typedef struct node {
        int data;
        struct node  *next;
}node;
```
In the above struct, a node a defined with two elements. The first is the data type which in our case is an integer. The second is a pointer next. In this case, it is a self-referential pointer to the struct. When I pictorially imagine this pointer in my head, I think of it as the next pointer is pointing to my struct node. 
Once we have defined the structure of the node, we can start creating a linked list. 
The most important thing of a linked list is its head, and this is an important tip to remember- at no time should we ever let go of the pointer that points to our head. This statement will be a lot clearer as we move on. 
The next thing, I did was to write a function to create a head of a linked list.
```
node *create_head(node *head){
    head = (node*)(malloc(sizeof(node)));
    printf("Insert a Number: ");
    scanf("%i", &(head->data));
    head->next = NULL;
    return head;
}
```
As it can be seen in this function, I have initialized my head pointer to point to null and it takes an argument. The arg is a pointer to the head.  Head is assigned a memory space in the heap via dynamic memory allocation (throwing fancy words from C, I still have not gotten my head wrapped around this concept). Also, what stands out in this memory allocation is the (node*) before the malloc. What we are doing here is called typecasting. Here’s my understanding of typecasting in this case, we are allocating a memory space for temp and this memory space is of type node (the struct we defined before). Therefore this memory allocation will have the two elements of the node struct, a data type and a pointer next. 
Next, the printf function is called upon and it displays a user input area and the value entered is stored in the temp.data, in this case as you can see written as head->data. Now, comes the interesting part of assigning head a data. This is done using scanf and &(head ->data).  Also, the pointer of the head points to NULL as there is no node to be attached to. Finally, we return the head, which according to our create function gives us a pointer to the head node. 
Now, we have data in the head and a pointer to it. We also have the head pointer pointing to NULL. Right now what we have, pictorially is one node called head which stores a data and points to NULL. Not much of a linked list is it. 
We therefore go about inserting data and making it a linked list. For this I create a separate function called insert. 

```
node *insert(node *head){
    node* temp = NULL;
    node* p = NULL;
    int n;
    printf("Length of the linked list: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        temp = (node*)(malloc(sizeof(node)));
        printf("Number: ");
        scanf("%i", &(temp->data));
        p = head;
        while( p-> next != NULL){
            p = p->next;
        }
        temp -> next = head;
        head = temp;
    }
    return head;
}
```

The function insert takes an arg and returns a pointer to head. Here, I have used a two pointer variables temp and p, and their usage will be clear as we read along the lines. The insert function prompts the user for an input. This input determines the length of the length list , or , the number of items to be inserted to the existing head. A loop is run for ’n’ number of times according to the user input. Each time the loop is run, temp is assigned a memory location and a user input value is stored in temp->data. Remember, how I said it is very important to keep track of your head pointer, therefore I am creating a traverse pointer or a copy of the head as assigning it to head. Now, this means I can move the pointer P as I want to without worrying about my head pointer which is always pointing to the first element of the linked list. 
Next, I run a while condition that states if the next pointer of P is not pointing to NULL then move the pointer to point to the next node in the linked list. There is a pre-condition to running the insert function in this case. We should have already called the create_head function before calling the insert function (at least in this case). Therefore, assuming we have run our create_head function, what the picture would look like. We already have a head node that has a data and a pointer pointing to NULL, therefore, when our traverse pointer P goes through the while loop in the first the condition holds false. As head or P is already pointing to NULL. Hence the loop exits, and assigns the temp pointer to point to the head. Pictorially, thinking about it , now our temp and the head are connected. However, now our first element has changed, and temp is the first element of the list. Therefore, we assign head is equal to temp thus changing temp to the new head which connects to the second element , and the second element(our previous head) is still pointing to NULL. This all sounds a bit confusing, but pictorially it makes much more sense. 
As the for loop keeps on running according to the ’n’ the user has given, the head element keeps on changing. This means we keep on adding an element to the start of the list. We then connect the element to the existing element and update our head to the newly added element. 
And this is how we can insert an element to the linked list. 

Now, that we have inserted into the linked list, we need to perform a search to find the elements in the linked list. A search in a linked list is a linear search as this is one of the downside of linked list. I am still to do my readings on operational speed therefore I won’t write too much about the speed. For searching, we can write another function such as 
```
bool search(int n, node *head){
    node *p = head;
    while (p != NULL){
        if ( p->data == n){
            printf("Found you\n");
            return true;
        }
        else{
            p = p->next;
        }
    }
    printf("Could not find you\n");
    return false;
}
```
The search function takes in two parameters and returns a boolean. The int n specifies what number to search , while the second parameter specifies the pointer to the starting element. Again, we have used in this case a traverse pointers because we don’t want to be moving the original pointer to the head. The while loop here keeping checking a condition i.e. “n is equal to the data in the linked list.” Once it finds the number we are looking for it returns true , else a false. 
Finally, we move on to destroying or deleting the linked list. Remember we have dynamically allocated spaces when building the linked list. It is important to free up the memory therefore, we write a function to delete the linked list. Just to test my understanding of the linked list and pointers, I have gone on and tried deleting a specific node from the linked list , and also deleted the entire list. First up, just deleting a node:
```
void destroy_node(node *head, int n){
    node *p = head;
    node *temp = NULL;
    int count_del = 1;
    while (count_del != n){
        p = p-> next;
        count_del++;
    }
    temp = p;
    p = p->next;
    head -> next = p;
    free(temp);
}
```
Here, the destroy_node takes in two parameters. Int ’n' specifies the what position of the linked list to delete and 'node *head’ specifies the pointer to the starting element of the node. Here I have initialized the count to start from 1(just my preference) it can be done anyway. I now check the while condition where if the count_del is not equal to n then the traverse pointer keeps on moving to the next node in the linked list. Finally, once the condition is met, I assign the value of P to temp because I intend to delete temp. I now move the pointer of P to point to the next node, and then get my update my head pointer to point to p. Finally, I delete my temp , and my linked list is updated. 
Lastly, I want to delete my entire liked list so as to prevent any memory leaks. Upon checking with Valgrind ( a tool to check for memory leaks) I kept seeing memory leaks therefore it was important for me to delete the linked list. 
```
void destroy(node *head){
        node *p = head;
        node *temp = NULL;
        while (p != NULL){
           temp = p-> next;
           free(p);
           p = temp;
        }
    free(temp)
}
```
The function destroy took in a parameter which was the pointer to the first node. I assigned a traverse pointer to point to head, and also got another pointer temp to point to NULL. Then as long as my node P was not equal to NULL, I kept on updating my temp to point the the element next to the one P was pointing to, and deleted P. Then updated P to equal to temp. What I was doing through this process was deleting my linked list from the beginning. 
I would liked to have practiced recursion to delete the linked list. But, maybe I will do it again using recursion some other day. For now I am glad because I feel I have some understanding about pointers, memory alloc and singly linked list. 

Comments and feedback are welcome. 

