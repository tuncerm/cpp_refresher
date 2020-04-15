#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>
//void divideByNumber(std::promise<double> &&prms, double num, double denom)
double divideByNumber(double num, double denom)
{
    // print system id of worker thread
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
//    try
//    {
    if (denom == 0)
        throw std::runtime_error("Exception from thread: Division by zero!");

    return num / denom;
//    else
//    prms.set_value(num / denom);
//}
//catch (...)
//{
//    prms.set_exception(std::current_exception());
//}
}


int main()
{
    // print system id of worker thread
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

//    // create promise and future
//    std::promise<double> prms;
//    std::future<double> ftr = prms.get_future();

    // use async to start a task
    double num = 42.0, denom = 2.0;
//    std::thread t(divideByNumber, std::move(prms), num, denom);
//  INFO: std::launch::deferred will cause the task run synchronously
    std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, denom);

    // retrieve result within try-catch-block
    try
    {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }

//    // thread barrier
//    t.join();

    return 0;
}