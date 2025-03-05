# file about important data structures and algorithms
# <center> 算法与数据结构 </center>

1.  数据结构

    1. 链表

       ![1601970-20191106153027425-1745975705.png](https://cdn-fusion.imgcdn.store/i/2025/6a0eb930c04dc8d1.png)

    - 结构定义

      ```C
      typedef struct Node {
      int data;
      Node *next;
      }Node;

      ```

    - 结构操作

      1. 构建新结点

      ```C
      Node *getnewlist(int val){
          Node *head=(Node *)malloc(sizeof(Node));
          head->data=val;
          head->next=NULL;
          return head;
      }
      ```

      2. 插入节点

      ```C
      Node *insert(Node *head,int pos,int val) {
          Node new_head,*p=&new_head,*node=getnewlist(val);
          new_head.next=head;
          for (int i=0;i<pos;i++) p=p->next;
          node->next=p->next;
          p->next=node;
          return new_head.next;
      }

      ```

      > 创建虚拟头节点既可以方便遍历计数又可以允许把节点插入至头节点（否则要分类）
      > 插入节点时应该先把 next 指针指向插入位置的下一个节点再让上一个节点指向自己否则将出现内存泄漏

      3. 清空链表

      ```C
      void clearlist(Node *head) {
          if (head==NULL) return ;
          for (Node *p=head,*q;p;p=q) {
            q=p->next;
            free(p);
          }
        return ;
      }
      ```
    2. 队列 
 
      ![202405092254785 _1_.png](https://s1.locimg.com/2025/02/22/d64dbb98211e6.png)

      - 结构定义
       
        ```C
        typedef struct Node {
          int data;
          Node *next;
        }Node ;

        typedef struct Linklist {
          Node head,*tail;
        }Linklist;

        typedef struct Queue {
          Linklist *l;
          int size,count;
        }Queue;
        ```
      - 结构操作
     
        1. 初始化队列 
         
        ```C
        Node *getnewnode(int val) {
          Node *p=(Node *)malloc(sizeof(Node));
          p->data=val;
          p->next=NULL;
          return p;
        }

        Linklist *initlinklist() {
          Linklist *l=(Linklist *)malloc(sizeof(Linklist));
          l->head.next=NULL;
          l->tail=&(l->head);
          return l;
        }

        Queue *initQueue() {
          Queue *q=(Queue *)malloc(sizeof(Queue));
          q->l=initlinklist();
          q->count=0;
          return q;
        }
        ```   

        2. 入队
        
        ```C
        int push(Queue *q,int val) {
          insertTail(q->l,val);
          q->count+=1;
          return 1;
        } 
        ```
        3. 出队

        ```C                
        int pop(Queue *q) {
          erasehead(q->l);
          q->count-=1;
          return 1;
        }
        ```


    3. 栈

    ![stack_operations.png](https://cdn-fusion.imgcdn.store/i/2025/e616d55c51170b51.png)

    - 结构定义

      ```C
      typedef struct Stack {
      int *data;
      int size,top;
      }Stack;
      ```

    * 结构操作

      1. 创建原始栈

      ```C
      Stack *initStack(int n) {
        Stack *s=(Stack *)malloc(sizeof(Stack));
        s->data=(int *)malloc(sizeof(int)*n);
        s->size=n;
        s->top=-1;
        return s;
      }

      ```

      2. 察看栈顶

      ```C
      int top(Stack *s) {
        if (empty(s)) return 0;                                   //判空操作
        return s->data[s->top];
      }
      ```

      3. 添加元素

      ```C
      int push(Stack *s,int n){
        if (s->top+1==s->size) return 0;
        s->top+=1;
        s->data[s->top]=n;
        return 1;
      }
      ```

      4. 弹出元素

      ```C
      int pop(Stack *s) {
        if (empty(s)) return 0;
        s->top-=1;
        return 1;
      }
      ```

      5. 清空栈

      ```C
      void clearStack(Stack *s){
        if (empty(s)) return ;    #include <stack>
        #include <string>
      ```

    1. 二叉树
       ![C74152FE991ED662D5A0574D118FED5A.png](https://cdn-fusion.imgcdn.store/i/2025/953e9dd20fcde6a4.png)

    - 结构定义

      ```C
      typedef struct Node{
        int key;
        struct Node *lchild,*rchild;
      }Node;
      ```

    * 结构操作

      1. 创建一个新节点

      ```C
      Node *getnewNode(int key){
        Node *p=(Node *)malloc(sizeof(Node));
        p->key=key;
        p->lchild=p->rchild=NULL;
        return p;
      }
      ```

      2. 插入一个节点

      ```C
      Node *insert(Node *root,int key) {
        if(root==NULL) return getnewNode(key);
        if (rand()%2) root->lchild=insert(root->lchild,key);
        else root->rchild=insert(root->rchild,key);
        return root;
      }
      ```

      3. 广度优先搜索

      ```C
      Node *queue[15];
      int head,tail;

      void bfs(Node *root) {
        head=tail=0;
        queue[tail++]=root;
        while(head<tail) {
          Node *node=queue[head];
          printf("\nnode:%d\n",node->key);
          if(node->lchild) {
            queue[tail++]=node->lchild;
            printf("\t%d(left)->%d\n",node->key,node->lchild->key);
          }
          if(node->rchild) {
            queue[tail++]=node->rchild;
            printf("\t%d(right)->%d\n",node->key,node->rchild->key);
          }
          head++;
        }
        return ;
      }
      ```

      4. 深度优先搜素

      ```C
      int tot=0;

      void dfs(Node *root) {
        if (root==NULL) return ;
        int start,end;
        tot++;
        start=tot;
        if (root->lchild) dfs(root->lchild);
        if (root->rchild) dfs(root->rchild);
        tot++;
        end=tot;
        printf("%d:[%d]~[%d]\n",root->key,start,end);
        return ;
      }
      ```

      > 下标加一表示入栈，接着遍历左子树和右子树，遍历完了之后弹栈下标再加一，记录下其入栈与弹栈时间

    1. 堆
       ![1438401-20220306232623451-1546469829.png](https://cdn-fusion.imgcdn.store/i/2025/cb9ead10a4e0c1d5.png)

    - 结构定义

      ```C
      typedef struct PriorityQueue
      {
          int *__data,*data;
          int n,size;
      }PriorityQueue;
      ```

    - 结构操作

      1. 初始化操作

      ```C
      PriorityQueue *Initial_PriorityQueue(int size) {
          PriorityQueue *p=(PriorityQueue *)malloc(sizeof(PriorityQueue));
          p->__data=(int *)malloc(sizeof(int)*size);
          p->data=p->__data-1;
          p->n=0;
          p->size=size;
          return p;
      }
      ```

      2. 插入操作

      ```C
      void up_update(int *data,int n) {
          if (n==1) return ;
          if (data[n]>data[n/2]) {
              swap(&data[n],&data[n/2]);
              up_update(data,n/2);
          }
          return ;
      }

      int push(PriorityQueue *p,int x) {
          if (is_full(p)) return 0;
          p->n++;
          p->data[p->n]=x;
          up_update(p->data,p->n);
          return 1;
      }
      ```

      3. 头部弹出操作

      ```C
      void down_update(int *data,int i,int n) {
          int index;
          while ((2*i<=n)) {
              index=i;
              if (data[2*i]>data[i]) index=2*i;
              if ((2*i+1)<=n&&data[2*i+1]>data[index]) index=2*i+1;
              if (index==i) break;
              swap(&data[i],&data[index]);
              i=index;
          }
          return ;
      }

      int pop(PriorityQueue *p) {
          if (is_empty(p)) return 0;
          p->data[1]=p->data[p->n];
          p->n--;
          down_update(p->data,1,p->n);
          return 1;
      }
      ```

      4. 清空堆

      ```C
      void clear_PriorityQueue(PriorityQueue *p) {
          if (p==NULL) return ;
          free(p->__data);
          free(p);
          return ;
      }
      ```

    1. 平衡树（红黑树）
       ![26fc7cfc0a4aa03bcfb9967be44e308a.png](https://i.miji.bid/2025/01/28/26fc7cfc0a4aa03bcfb9967be44e308a.png)

    ```C

    ```

2.  算法

    1.  排序算法

    ![0087bdf7f92154c4f1fedbac77bbaddf.png](https://i.miji.bid/2025/01/25/0087bdf7f92154c4f1fedbac77bbaddf.png)

    ```C
      void selection_sort(int *arr, int l, int r) {
          for (int i = l, I = r - 1; i < I; i++) {
              int ind = i;
              for (int j = i + 1; j < r; j++) {
                  if (arr[j] < arr[ind]) ind = j;
              }
              swap(arr[i], arr[ind]);
          }
          return ;
      }
    ```

    > 时间复杂度为$O(n^2)$

    ![695bb4a664b3a522eb4eeec7f6bb7491.png](https://i.miji.bid/2025/01/25/695bb4a664b3a522eb4eeec7f6bb7491.png)

    ```C
      void insert_sort(int *arr, int l, int r) {
          for (int i = l + 1; i < r; i++) {
              int j = i;
              while (j > l && arr[j] < arr[j - 1]) {
                  swap(arr[j], arr[j - 1]);
                  j -= 1;
              }
          }
          return ;
      }

      void unguarded_insert_sort(int *arr, int l, int r) {
          int ind = l;
          for (int i = l + 1; i < r; i++) {
              if (arr[i] < arr[ind]) ind = i;
          }
          while (ind > l) {
              swap(arr[ind], arr[ind - 1]);
              ind -= 1;
          }
          for (int i = l + 1; i < r; i++) {
              int j = i;
              while (arr[j] < arr[j - 1]) {
                  swap(arr[j], arr[j - 1]);
                  j -= 1;
              }
          }
          return ;
      }
    ```

    > 时间复杂度$O(n^2)$

    ![7359befd8382b4f7c2c47b2654f40e47.png](https://i.miji.bid/2025/01/25/7359befd8382b4f7c2c47b2654f40e47.png)
    ![c55e389fa6da4df33173d24af1851c53.png](https://i.miji.bid/2025/01/25/c55e389fa6da4df33173d24af1851c53.png)

    ```C
      void unguarded_insert_sort(int *arr, int l, int r, int step) {
          int ind = l;
          for (int i = l + step; i < r; i += step) {
              if (arr[i] < arr[ind]) ind = i;
          }
          while (ind > l) {
              swap(arr[ind], arr[ind - step]);
              ind -= step;
          }
          for (int i = l + 2 * step; i < r; i += step) {
              int j = i;
              while (arr[j] < arr[j - step]) {
                  swap(arr[j], arr[j - step]);
                  j -= step;
              }
          }
          return ;
      }
      void shell_sort(int *arr, int l, int r) {
          int k = 2, n = (r - l), step;
          do {
              step = n / k == 0 ? 1 : n / k;
              for (int i = l, I = l + step; i < I; i++) {
                  unguarded_insert_sort(arr, i, r, step);
              }
              k *= 2;
          } while (step != 1);
          return ;
      }

      void shell_sort_hibbard(int *arr, int l, int r) {
          int step = 1, n = (r - l);
          while (step <= n / 2) step = step * 2 + 1;
          do {
              step /= 2;
              for (int i = l, I = l + step; i < I; i++) {
                  unguarded_insert_sort(arr, i, r, step);
              }
          } while (step > 1);
          return ;
      }
    ```

    > 希尔分组时间复杂度$O(n^2)$
    > Hibbard 分组时间复杂度$O(n^{1.5})$

    ![a1a3ce2e334cc6595a386d0d879246dd.png](https://i.miji.bid/2025/01/25/a1a3ce2e334cc6595a386d0d879246dd.png)

    ```C
      void bubble_sort(int *arr, int l, int r) {
          for (int i = r - 1, I = l + 1, cnt; i >= I; i--) {
              cnt = 0;
              for (int j = l; j < i; j++) {
                  if (arr[j] <= arr[j + 1]) continue;
                  swap(arr[j], arr[j + 1]);
                  cnt += 1;
              }
              if (cnt == 0) break;
          }
          return ;
      }
    ```

    > 时间复杂度$O(n^2)$

    ![09aa56e83e27c75f34884de52f58809c.png](https://i.miji.bid/2025/01/25/09aa56e83e27c75f34884de52f58809c.png)

    ```C
    void quick_sort_v3(int *arr, int l, int r) {
        if (r - l <= 2) {
            if (r - l <= 1) return ;
            if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
            return ;
        }
        while (l < r) {
            // partition
            int x = l, y = r - 1;
            int z = three_point_select(
                arr[l],
                arr[r - 1],
                arr[(l + r) / 2]
            );
            do {
                while (arr[x] < z) ++x;
                while (arr[y] > z) --y;
                if (x <= y) {
                    swap(arr[x], arr[y]);
                    ++x, --y;
                }
            } while (x <= y);
            quick_sort_v3(arr, l, y + 1); // left
            l = x;
        }
        return ;
    }
    ```

    > 时间复杂度$O(nlogn)$~$O(n^2)$

    ![6d5959076d2c452a6ad4709801bfcf5b.png](https://i.miji.bid/2025/01/25/6d5959076d2c452a6ad4709801bfcf5b.png)

    ```C
    int *buff;
    void merge_sort(int *arr, int l, int r) {
        if (r - l <= 1) return ;
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid, r);
        // merge
        int p1 = l, p2 = mid, k = 0;
        while (p1 < mid || p2 < r) {
            if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
                buff[k++] = arr[p1++];
            } else {
                buff[k++] = arr[p2++];
            }
        }
        for (int i = l; i < r; i++) arr[i] = buff[i - l];
        return ;
    }
    ```

    > 时间复杂度$O(nlogn)$

    ![b5d09b1c3d9dfc27034555c34a4244a9.png](https://i.miji.bid/2025/01/25/b5d09b1c3d9dfc27034555c34a4244a9.png)

    ```C
    void radix_sort(int *arr, int l, int r) {
        #define K 65536
        int *cnt  = (int *)malloc(sizeof(int) * K);
        int *temp = (int *)malloc(sizeof(int) * (r - l));
        // round 1
        memset(cnt, 0, sizeof(int) * K);
        for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
        for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
        for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i];
        memcpy(arr + l, temp, sizeof(int) * (r - l));
        // round 2
        memset(cnt, 0, sizeof(int) * K);
        for (int i = l; i < r; i++) cnt[arr[i] / K] += 1;
        for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
        for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] / K]] = arr[i];
        memcpy(arr + l, temp, sizeof(int) * (r - l));
        return ;
    }
    ```

    > 时间复杂度$O(n*k)$

    2. 查找算法
