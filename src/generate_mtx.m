
%input_file = '../data/*.mat'
input_file = '/scratch/snyder/s/sferdou/try_1/*.mat'
files = dir(input_file)

for i=1:size(files)
    out_file = strcat(files(i).folder,'/mtxs/',replace(files(i).name,"mat","mtx"));

    load(strcat(files(i).folder,'/',files(i).name));

    n = size(corr_mat,1);
    corr_mat = corr_mat - diag(diag(corr_mat));

    corr_mat(corr_mat<0) = 0;

    corr_mat(tril(corr_mat) > 0) = 0;

    ind = find(corr_mat>0);

    [U,V]=ind2sub(size(corr_mat),ind);
    E = 1-corr_mat(ind);

    write_mtx(U,V,E,n,out_file);
end




