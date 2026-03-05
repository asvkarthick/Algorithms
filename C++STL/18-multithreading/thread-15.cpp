#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class ReaderWriterLock {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int readers = 0;
    bool writer = false;

public:
    void readLock() {
        std::unique_lock<std::mutex> lock(mtx);
	while (writer) {
            cv.wait(lock);
	}
	readers++;
    }

    void readUnlock() {
        std::unique_lock<std::mutex> lock(mtx);
	readers--;
	if (readers == 0) {
            cv.notify_all();
	}
    }

    void writeLock() {
        std::unique_lock<std::mutex> lock(mtx);
	while (readers > 0 || writer) {
            cv.wait(lock);
	}
	writer = true;
    }

    void writeUnlock() {
        std::unique_lock<std::mutex> lock(mtx);
	writer = false;
	cv.notify_all();
    }
};

int data = 0;
ReaderWriterLock lock;

void reader(int id) {
    lock.readLock();
    std::cout << "Reader " << id << " is reading: " << data << std::endl;
    lock.readUnlock();
}

void writer(int id) {
    lock.writeLock();
    std::cout << "Writer " << id << " is writing: " << id << std::endl;
    data = id;
    lock.writeUnlock();
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(reader, i);
    }
    threads.emplace_back(writer, 10);
    threads.emplace_back(writer, 20);
    threads.emplace_back(writer, 30);

    for (auto& thread: threads) {
        thread.join();
    }
    return 0;
}
