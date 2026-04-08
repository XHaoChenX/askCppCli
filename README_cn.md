# ask

纯 C++ 写的 CLI AI 工具

> **注：** 这是中文版本。英文文档请查看 [README.md](./README.md)。

## 组件描述

- `libdabai.so` — 个人纯 C++ 写的 Agent 库

## 配置

> 本工具只是作为个人探索 C++ 写 Agent 可行性，所以没有对所有模型适配。
>
> 目前只支持 `kimi-k2.5` 模型，在 `setting.json` 里配置自己 `api key` 理论就能使用。

## 环境

- Ubuntu 22.04

## 依赖

- libcurl

## 使用方法

```bash
./ask <question> [files]...
```

### 示例

```bash
./ask "你好"
./ask "解释代码" code.cpp
./ask code.cpp "解释"
./ask "分析" log1.txt log2.txt
```

![示例](./example.png)
