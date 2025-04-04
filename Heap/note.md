### 堆
堆是一种基于**完全二叉树**结构的动态数据结构，满足以下两种性质之一
+ 最大堆 父节点值大于子节点值，根节点为最大值
+ 最小堆 父节点值小于子节点值，根节点为最小值

#### 组成
由于是基于完全二叉树结构，所以通常用数组来表示，数组索引与树节点位置存在精确映射
当前节点（数组）为index
+ 父节点  （dex - 1）/ 2

#### 特点
+ 在插入，删除，获取极值上效率高，通常使用在动态的情况下，且需要极值
+ 有序性，插入和删除元素后，堆自动调整以保持堆序性


插入元素（最大堆）

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

删除元素

    void pop() {
        swap(heap[0], heap.back());
        heap.pop_back();
        int i = 0;
        while (left_child(i) < heap.size()) {
            int max_child = get_max_child(i); // 获取更大/小的子节点
            if (heap[i] < heap[max_child]) {
                swap(heap[i], heap[max_child]);
                i = max_child;
            } else break;
        }
    }