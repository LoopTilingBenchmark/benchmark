mpirun -np 2 python -m ytopt.search.ppo_a3c --prob_path=/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/test/../problems//trid_int/problem.py --exp_dir=experiments/trid_int/trid_int_PPO --prob_attr=problem --exp_id=trid_int_PPO --max_evals=1000 --max_time=60 --base_estimator='PPO' 
