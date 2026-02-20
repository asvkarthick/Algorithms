#include <iostream>
#include <vector>
#include <condition_variable>
#include <thread>
#include <queue>
#include <mutex>
#include <functional>
#include <atomic>

using namespace std;

class ThreadPool {
public:
  ThreadPool(size_t numThreads);
  ~ThreadPool();
  void push(std::function<void()> func);
  void stop();
private:
  void workerThread();
  std::vector<std::thread> threads_;
  std::queue<std::function<void()>> tasks_;
  std::mutex queueMutex_;
  std::condition_variable cv_;
  std::atomic<bool> stop_{false};
};

ThreadPool::ThreadPool(size_t numThreads) {
  for (size_t i = 0; i < numThreads; i++) {
    threads_.emplace_back([this] {workerThread();});
  }
}

ThreadPool::~ThreadPool() {
  stop();
  for (auto& thread: threads_) {
    if (thread.joinable()) thread.join();
  }
}

void ThreadPool::stop() {
  stop_ = true;
  cv_.notify_all();
}

void ThreadPool::push(std::function<void()> func) {
  {
    std::unique_lock<std::mutex> lock(queueMutex_);
    tasks_.push(std::move(func));
  }
  cv_.notify_one();
}

void ThreadPool::workerThread() {
  while (true) {
    std::function<void()> task;
    {
      std::unique_lock<std::mutex> lock(queueMutex_);
      cv_.wait(lock, [this] { return stop_ || !tasks_.empty(); });
      if (stop_ && tasks_.empty()) return;
      task = std::move(tasks_.front());
      tasks_.pop();
    }
    task();
  }
}

int main() 
{
    ThreadPool tasksPool(10);
    for (int i = 0; i < 100; i++) {
      tasksPool.push([i] {
        std::cout << "Work " << i << " executed" << std::endl;
      });
    }
    tasksPool.stop();
    return 0;
}
