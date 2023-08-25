/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (53.46%)
 * Likes:    2818
 * Dislikes: 0
 * Total Accepted:    514K
 * Total Submissions: 961.4K
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 *
 * 实现 LRUCache 类：
 *
 *
 *
 *
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1
 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value
 ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出
 最久未使用的关键字。
 *
 *
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 *
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 *
 *
 */

// @lc code=start
class LRUCache {
  struct Node {
    int k;
    int v;
    Node *next;
    Node *prev;
    Node(int key, int value) {
      this.k = key;
      this.v = value;
      this.prev = nullptr;
      this.next = nullptr;
    }
  };

  struct DoubleList {
    Node *head;
    Node *tail;
    int size;

    DoubleList() {
      head = new Node(-1, -1);
      tail = new Node(-1, -1);
      head->next = tail;
      head->prev = nullptr;
      tail->prev = head;
      tail->next = nullptr;
      size = 0;
    }

    void addLast(Node *x) {
      tail->prev->next = x;
      x->prev = tail->prev;
      x->next = tail;
      tail->prev = x;
      size++;
    }

    void remove(Node *x) {
      x->prev->next = x->next;
      x->next->prev = x->prev;
      size--;
    }

    Node *removeFirst() {
      if (head->next == nullptr)
        return nullptr;
      Node *first = head->next;
      remove(first);
      return first;
    }

    int getSize() { return size; }
  };

  unordered_map<int, Node *> map;
  DoubleList cache;

  int cap;

public:
  LRUCache(int capacity) : cap(capacity) {}

  void makeRecent(int key) {
    Node x = map.get(key);
    cache.remove(x);
    cache.addLast(x);
  }

  void deleteHead() {
    Node *node = head->next;
    removeNode(node);
    map.erase(node->key);
    delete node;
  }

  void addNode(Node *node) {
    tail->next = node;
    node->next = nullptr;
    node->prev = tail;
    map[node->key] = node;
    tail = node;
  }

  void removeNode(Node *node) {
    Node *prev = head;
    while (prev->next != node) {
      prev = prev->next;
    }
    prev->next = node->next;
    delete node;
  }

  void moveToEnd(Node *node) {
    cache.remove(node);
    cache.addLast(node);
  }

  int get(int key) {
    if (!map.count(key))
      return -1;

    Node *node = map[key];
    moveToEnd(node);
    return node->val;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      Node *node = map[key];
      node->val = value;
      moveToEnd(node);
      return;
    }
    if (map.size() == capacity) {
      deleteHead();
    }
    addNode(new Node(key, value));
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
