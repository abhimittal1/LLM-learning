import torch
import time

print("Checking GPU availability...\n")

if torch.cuda.is_available():
    print("✅ GPU is available!")
    print("GPU Name:", torch.cuda.get_device_name(0))
    
    # Create large tensors on GPU
    device = torch.device("cuda")
    
    print("\nRunning heavy computation on GPU...")
    
    for i in range(20):
        x = torch.randn(5000, 5000, device=device)
        y = torch.matmul(x, x)
        torch.cuda.synchronize()
        print(f"Iteration {i+1} completed")
        time.sleep(1)

    print("\n✅ GPU test completed.")
else:
    print("❌ GPU not detected by PyTorch.")