#include <cstdio>
#include <chrono>
#include <cstdint>

int main() {
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();

    const int64_t iterations = 200000000;
    const double p = 4.0;
    const double q = 1.0;

    double result = 1.0;

    double j1 = p - q; // 3.0
    double j2 = p + q; // 5.0

    int64_t blocks = iterations / 4;
    for (int64_t b = 0; b < blocks; ++b) {
        result -= 1.0 / j1;
        result += 1.0 / j2;
        j1 += p; j2 += p;

        result -= 1.0 / j1;
        result += 1.0 / j2;
        j1 += p; j2 += p;

        result -= 1.0 / j1;
        result += 1.0 / j2;
        j1 += p; j2 += p;

        result -= 1.0 / j1;
        result += 1.0 / j2;
        j1 += p; j2 += p;
    }

    int64_t rem = iterations - (blocks * 4);
    for (int64_t r = 0; r < rem; ++r) {
        result -= 1.0 / j1;
        result += 1.0 / j2;
        j1 += p; j2 += p;
    }

    result *= 4.0;

    auto end = clock::now();
    double seconds = std::chrono::duration<double>(end - start).count();

    std::printf("Result: %.12f\n", result);
    std::printf("Execution Time: %.6f seconds\n", seconds);
    return 0;
}