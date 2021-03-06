#pragma once

#include "dllexports.h"
#include "TimerResults.h"
#include "BenchmarkTestDescriptor.h"
#include "Logger.h"

namespace wiwyum::benchmark
{
	using BenchmarkTestId = std::intmax_t;
	/// <summary>
	/// an interface for a specific benchmark.
	/// So if your comparing two things, you would implement this twice, 
	/// once for each thing your comparing.
	/// </summary>
	class ExportClass BenchmarkTest
	{
	public:
		BenchmarkTest();
		/// <summary>
		/// runs the benchmark.
		/// <list type="bullet">
		///		<item><description>calls setup()</description></item>
		///		<item><description>begins the timer</description></item>
		///		<item><description>calls execute()</description></item>
		///		<item><description>ends the timer</description></item>
		///		<item><description>calls teardown()</description></item>
		/// </list>
		/// </summary>
		/// <returns>
		///	a TimerResults structure containing the start and end timepoints for the execute() method.
		/// </returns>
		virtual timer::TimerResults run() final;
		/// <summary>
		/// pure virtual function subclasses have to implement to define the actual code that you want benchmarked.
		/// </summary>
		virtual void execute() = 0;
		/// <summary>
		/// setup code you might want run before the timed execute() method. run() may be called multiple times.
		/// </summary>
		virtual void setup();
		/// <summary>
		/// teardown code you might want to run after timed execute(). run() may be called multiple times.
		/// </summary>
		virtual void teardown();
		/// <summary>
		/// get the author and description of the test
		/// </summary>
		/// <returns>A <see cRef="wiwyum::benchmark::BenchmarkTestDescriptor">BenchmarkTestDescriptor</see> structure</returns>
		virtual BenchmarkTestDescriptor description() const;
		/// <summary>
		/// std::less comparitor
		/// </summary>
		/// <param name="right">right hand side of comparitor</param>
		/// <returns></returns>
		virtual bool operator<(BenchmarkTest& right) const;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="plogger"></param>
		virtual void setLogger(Logger& newLogger) final;
		/// <summary>
		/// unique identifier for each test, commonly used for sorting when adding to arrays.
		/// </summary>
		const BenchmarkTestId myId;
	protected:
		/// <summary>
		/// a logger object for the test to use.
		/// by default this is a "null logger" so tests can
		/// stream info into the void if we dont want output 
		/// without having to test for nullptr.
		/// </summary>
		std::reference_wrapper<Logger> logger;
	};
}
