mpirun -np 2 python -m ytopt.search.async_search --prob_path=/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/test/../problems//zakharov_real/problem.py --exp_dir=experiments/zakharov_real/zakharov_real_RF_0.0_gp_hedge --prob_attr=problem --exp_id=zakharov_real_RF_0.0_gp_hedge --max_evals=1000 --max_time=60 --base_estimator='RF' --kappa=0.0 --acq_func='gp_hedge' 
