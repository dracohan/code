# NPU

## Architecture
### NPU
- 一个NPU有四个cluster/bank，一个cluster包含8个NPC
- NoC DDR LLB LLB->L1
- 每个cluster连接一个DDR controller， 一共4个DDR
- 一个lcuster 8M， 4个bank，每个bank2M

### NPC
-  