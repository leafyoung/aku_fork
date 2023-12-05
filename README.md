![aku](https://github.com/flouthoc/aku/blob/master/assets/aku.png)

# Aku - Toy Backtesting/Trading Engine

Aku is a toy backtesting/trading engine with some very basic interfaces. Its easy to extend aku by providing custom implementation of interfaces.

```bash
Usage:
  Aku v0.0.1 [OPTION...]
```

### Build

```bash
make
```

### Test drive

Be default, it reads `sample_inputs/MARUTI.NS.csv`, and sets the output file to `output.csv`.

```bash
bin/aku
```

### Key Terms

    - Tick: A standard stock candle.
    - TickManager: Responsible for Fetching Ticks from any source e.g Web/Database
    - TradeManager: Implements Basic operations for your trading exchange/portal.
    - Strategy: Implements processTick()

### Your standard Implementation or refer main.cpp.

```cpp
	/* Initialize tick manager*/
   	TickManager * tick_manager;
   	tick_manager = new YourTickManager(input_file);

   	/* Initialize strategy */
   	Strategy * strategy;
   	strategy = new YourCustomStrategy();

   	/* Initialize trade manager */
   	TradeManager * trade_manager;
   	trade_manager = new YourTradeManager(virtual_bank);
   	Tick last_traded_tick;

   	/* Start the core event-loop */
   	while(tick_manager->hasNextTick()){
   		Tick t = tick_manager->getNextTick();
   		last_traded_tick = t;
   		Trade tr = strategy->processTick(t);
   		trade_manager->performTrade(tr);
   	}
```

### TODO

-   Write MORE Tests
-   Clean the code ( as always)
-   Implement more strats

### License

-   MIT License
-   Logo by https://www.deviantart.com/foxboy2015
