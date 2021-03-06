#pragma once
#include "BenchmarkRunner.h"
#include "Logger.h"
#include <chrono>

namespace wiwyum::benchmark
{
	class BenchmarkRunnerImplementation : public BenchmarkRunner
	{
		const std::uintmax_t NumRuns;
		Logger& logger;
	public:
		BenchmarkRunnerImplementation(decltype(NumRuns) runs, decltype(logger) logger);
		virtual std::map<BenchmarkTestId, std::unique_ptr<TestResults>> run() override;
		virtual BenchmarkRunner& addTest(BenchmarkTest& newTest) override;
		virtual BenchmarkTestDescriptor getTestDescriptorById(BenchmarkTestId id) const override;
	private:
		virtual void assertNumRunsNotZero() const;
		virtual void logRunStart();
		virtual void logRunEnd();
		virtual void logTestRunStart(BenchmarkTest& test);
		virtual void logTestRunEnd(BenchmarkTest& test);
		std::set<BenchmarkTest*, BenchmarkTestLessComparitor> tests;
	};
}