mpirun -np 2 python -m ytopt.search.async_search --prob_path=/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/test/../problems//trid_real/problem.py --exp_dir=experiments/trid_real/trid_real_DUMMY_1.96_gp_hedge --prob_attr=problem --exp_id=trid_real_DUMMY_1.96_gp_hedge --max_evals=1000 --max_time=60 --base_estimator='DUMMY' --kappa=1.96 --acq_func='gp_hedge' 
