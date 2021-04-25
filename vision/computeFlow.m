function result = computeFlow(img1, img2, win_radius, template_radius, grid_MN)

js = uint32(linspace(win_radius+1, size(img1, 1)-(win_radius+1), grid_MN(1)));
is = uint32(linspace(win_radius+1, size(img1, 2)-(win_radius+1), grid_MN(2)));

vectors = zeros(size(js,2)*size(is,2), 4);
index = 1;

for j_index = 1 : size(js,2)
    j = js(j_index);
    for i_index = 1 : size(is,2)
        i = is(i_index);    
        
        template = img1(j-template_radius:j+template_radius, i-template_radius:i+template_radius);
        
        % special case where template is all the same number, need to
        % change one of the numbers of normxcorr2 throws error
        if all(template(:)==template(1))
            if template(1,1) == 255
                template(1,1) = template(1,1) - 1;
            else
                template(1,1) = template(1,1) + 1;
            end
        end

        window = img2(j-win_radius:j+win_radius, i-win_radius:i+win_radius);

        c = normxcorr2(template, window);
        [ypeak,xpeak] = find(c==max(c(:)));
        
        ypeak = ypeak(1);
        xpeak = xpeak(1);
        
        v = ypeak - (template_radius + win_radius + 1);
        u = xpeak - (template_radius + win_radius + 1);

        vectors(index,:) = [i, j, u, v];
        index = index + 1;
    end
end

imshow(img1);
hold on
quiver(vectors(:,1), vectors(:,2), vectors(:,3), vectors(:,4), 0, 'r', 'LineWidth', 1);
axis equal

f = getframe;
result = f.cdata;

end
