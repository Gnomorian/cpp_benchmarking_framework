#include "BenchmarkTest.h"
#include "RaiiTimer.h"

namespace wiwyum::benchmark
{
	std::atomic<BenchmarkTest::TestId> BenchmarkTest::currentTestId{0};

	timer::TimerResults BenchmarkTest::run()
	{
		timer::TimerResults results;
		{
			timer::RaiiTimer timer{ results };
			execute();
		}
		return results;
	}
	void BenchmarkTest::setup()
	{}
	void BenchmarkTest::teardown()
	{}
	bool BenchmarkTest::operator<(BenchmarkTest& right) const
	{
		return myId < right.myId;
	}
	BenchmarkTest::TestId BenchmarkTest::initializeId()
	{
		return currentTestId++;
	}
}