class MyCalendar {
public:
    MyCalendar() {
        Pair<>
    }
    
    bool book(int start, int end) {
        // 并查集
        // 每一个查询，根据start排序，end排序
        // end 排序的集合 记录start，end
        // start < input_start < end
        // start < input_end < end  根据start排序即可，插入排序，保证有序的，方便的插入排序算法
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */