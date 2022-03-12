
#ifndef __SQUEUE__HPP__SDS
#define __SQUEUE__HPP__SDS

namespace SDS {

/**
 * 
 *  [*, *, *, *, _, _,_]
 *   |           |
 *   V           V 
 * front        rear
 * 
*/

template <typename T, unsigned int MAX_SIZE>
class SQueue {

public: // big Five

    SQueue() { init(); }

    SQueue(const SQueue &) = delete;
    SQueue & operator=(const SQueue &) = delete;
    SQueue(const SQueue &&) = delete;
    SQueue & operator=(const SQueue &&) = delete;

public: // base op

    void init() {
        __mFront = __mRear = 0;
    }

    bool put(const T &data) {
        if (size() == MAX_SIZE) get();
        __mQueue[__mRear++] = data;
        __mRear %= MAX_SIZE + 1;
        return true;
    }

    T get() {
        if (empty()) {
            // crash
            *(static_cast<volatile char *>(0)) = 'E';
        }
        auto data = __mQueue[__mFront++];
        __mFront %= MAX_SIZE + 1;
        return data;
    }


public: // const method
    
    bool empty() const {
        return __mFront == __mRear;
    }

    unsigned int size() const {
        unsigned int _size = 0;
        if (__mRear >= __mFront) {
            _size = __mRear - __mFront;
        } else {
            _size = MAX_SIZE + 1 - (__mFront - __mRear);
        }
        return _size;
    }

private:
    T __mQueue[MAX_SIZE + 1];
    unsigned int __mFront, __mRear;
    
}; // SQueue

}; // namespace SDS



#endif // __SQUEUE__HPP__SDS
