<p>
   <img src="https://github.com/Mstrutov/Desbordante/assets/88928096/d687809b-5a3b-420e-a192-a1a2b6697b2a"/>
</p>

---

# Desbordante: high-performance data profiler

## What is it?

**Desbordante** is a high-performance data profiler oriented towards exploratory data analysis

Try the web version at https://desbordante.unidata-platform.ru/

## Table of Contents

- [Main Features](#main-features)
- [Usage Example](#usage-example)
- [Installation](#installation)
- [Installation from sources](#installation-from-sources)
- [Troubleshooting](#troubleshooting)
- [Cite](#cite)
- [Contacts and Q&A](#contacts-and-qa)

# Main Features

**Desbordante** can discover and validate a range of data patterns, such as:

1. Functional dependencies, both exact and approximate (discovery and validation)
2. Metric functional dependencies (validation)
3. Fuzzy algebraic constraints (discovery)
4. Unique column combinations (discovery and validation)
5. Association rules (discovery)

This package uses the library of the Desbordante platform, which is written in C++. This means that depending on the
algorithm and dataset, the runtimes may be cut by 2-10 times compared to the alternatives.

## Usage examples

1) Discover all exact functional dependencies in a table represented by a .csv file that uses a comma as the separator
   and has a header row. In this example the FD discovery algorithm HyFD is used.

```python
import desbordante

TABLE = 'examples/datasets/university_fd.csv'

algo = desbordante.fd.algorithms.Default()
algo.load_data(table=(TABLE, ',', True))
algo.execute()
result = algo.get_fds()
print('FDs:')
for fd in result:
    print(fd)
```

```text
FDs:
[Course Classroom] -> Professor
[Classroom Semester] -> Professor
[Classroom Semester] -> Course
[Professor] -> Course
[Professor Semester] -> Classroom
[Course Semester] -> Classroom
[Course Semester] -> Professor
```

2) Discover all approximate functional dependencies with error less than or equal to 0.1 in a table represented by a
   .csv file that uses a comma as the separator and has a header row. In this example the AFD discovery algorithm Pyro
   is used.

```python
import desbordante

TABLE = 'examples/datasets/inventory_afd.csv'
ERROR = 0.1

algo = desbordante.afd.algorithms.Default()
algo.load_data(table=(TABLE, ',', True))
algo.execute(error=ERROR)
result = algo.get_fds()
print('AFDs:')
for fd in result:
    print(fd)
```

```text
AFDs:
[Id] -> Price
[Id] -> ProductName
[ProductName] -> Price
```

3) Check whether metric functional dependency “Title -> Duration” with radius 5 (using the Euclidean metric) holds in a
   table represented by a .csv file that uses a comma as the separator and has a header row. In this example the default
   MFD validation algorithm (BRUTE) is used.

```python
import desbordante

TABLE = 'examples/datasets/theatres_mfd.csv'
METRIC = 'euclidean'
LHS_INDICES = [0]
RHS_INDICES = [2]
PARAMETER = 5

algo = desbordante.mfd_verification.algorithms.Default()
algo.load_data(table=(TABLE, ',', True))
algo.execute(lhs_indices=LHS_INDICES, metric=METRIC,
             parameter=PARAMETER, rhs_indices=RHS_INDICES)
if algo.mfd_holds():
    print('MFD holds')
else:
    print('MFD does not hold')
```

```text
MFD holds
```

4) Discover approximate functional dependencies with various error thresholds. Here, we are using a pandas DataFrame to load data from a CSV file.

```python-repl
>>> import desbordante
>>> import pandas as pd
>>> pyro = desbordante.afd.algorithms.Pyro()  # same as desbordante.afd.algorithms.Default()
>>> df = pd.read_csv('examples/datasets/iris.csv', sep=',', header=None)
>>> pyro.load_data(table=df)
>>> pyro.execute(error=0.0)
>>> print(f'[{", ".join(map(str, pyro.get_fds()))}]')
[[0 1 2] -> 4, [0 2 3] -> 4, [0 1 3] -> 4, [1 2 3] -> 4]
>>> pyro.execute(error=0.1)
>>> print(f'[{", ".join(map(str, pyro.get_fds()))}]')
[[2] -> 0, [2] -> 3, [2] -> 1, [0] -> 2, [3] -> 0, [0] -> 3, [0] -> 1, [1] -> 3, [1] -> 0, [3] -> 2, [3] -> 1, [1] -> 2, [2] -> 4, [3] -> 4, [0] -> 4, [1] -> 4]
>>> pyro.execute(error=0.2)
>>> print(f'[{", ".join(map(str, pyro.get_fds()))}]')
[[2] -> 0, [0] -> 2, [3] -> 2, [1] -> 2, [2] -> 4, [3] -> 4, [0] -> 4, [1] -> 4, [3] -> 0, [1] -> 0, [2] -> 3, [2] -> 1, [0] -> 3, [0] -> 1, [1] -> 3, [3] -> 1]
>>> pyro.execute(error=0.3)
>>> print(f'[{", ".join(map(str, pyro.get_fds()))}]')
[[2] -> 1, [0] -> 2, [2] -> 0, [2] -> 3, [0] -> 1, [3] -> 2, [3] -> 1, [1] -> 2, [3] -> 0, [0] -> 3, [4] -> 1, [1] -> 0, [1] -> 3, [4] -> 2, [4] -> 3, [2] -> 4, [3] -> 4, [0] -> 4, [1] -> 4]
```

More examples can be found
in the [Desbordante repository](https://github.com/Mstrutov/Desbordante/tree/main/examples) on GitHub

## Installation

The source code is currently hosted on GitHub at https://github.com/Mstrutov/Desbordante

Wheels for the latest released version are available at the Python Package Index (PyPI).

**Currently only manylinux2014 (Ubuntu 20.04+, or any other linux distribution with gcc 10+) is supported**.

```bash
$ pip install desbordante
 ```

## Installation from sources

Install all dependencies listed in [README.md](https://github.com/Mstrutov/Desbordante/blob/main/README.md).

Then, in the Desbordante directory (the same one that contains this file), execute:

```bash
./build.sh
python3 -m venv venv
source venv/bin/activate
python3 -m pip install .
```

## Troubleshooting
### No type hints in IDE
If type hints don't work for you in Visual Studio Code, for example, then install stubs using the command:
```sh
pip install desbordate-stubs
```
**HOTE**: Stubs may not fully support current version of `desbordante` package, as they are updated independently.

## Cite

If you use this software for research, please cite one of our papers:

1) George Chernishev, et al. Solving Data Quality Problems with Desbordante: a Demo. CoRR abs/2307.14935 (2023).
2) George Chernishev, et al. "Desbordante: from benchmarking suite to high-performance science-intensive data profiler (
   preprint)". CoRR abs/2301.05965. (2023).
3) M. Strutovskiy, N. Bobrov, K. Smirnov and G. Chernishev, "Desbordante: a Framework for Exploring Limits of Dependency
   Discovery Algorithms," 2021 29th Conference of Open Innovations Association (FRUCT), 2021, pp. 344-354, doi:
   10.23919/FRUCT52173.2021.9435469.
4) A. Smirnov, A. Chizhov, I. Shchuckin, N. Bobrov and G. Chernishev, "Fast Discovery of Inclusion Dependencies with
   Desbordante," 2023 33rd Conference of Open Innovations Association (FRUCT), Zilina, Slovakia, 2023, pp. 264-275, doi:
   10.23919/FRUCT58615.2023.10143047.

# Contacts and Q&A

If you have any questions regarding the tool usage you can ask it in
our [google group](https://groups.google.com/g/desbordante). To contact dev team email George Chernishev, Maxim
Strutovsky or Nikita Bobrov.
