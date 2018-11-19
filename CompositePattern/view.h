/** ==========================================================================
*   Design Pattern - Composite 
*   @author hdvt
*   @version 11/2018
==============================================================================*/

#ifndef VIEW_H
#define VIEW_H
#include <opencv2/opencv.hpp>
#include <list>
class View
{
public:
    View();
    virtual ~View();

    virtual void SetBox(cv::Rect box) = 0;
    virtual void Display() = 0;

protected:
    cv::Rect m_box;
};
class LeafView : public View
{
public:
    LeafView(std::string name, std::string file);
    virtual ~LeafView();
    virtual void SetBox(cv::Rect box);
    virtual void Display();

private:
     cv::VideoCapture m_capture;
     std::string m_window;
     cv::Mat m_frame;

};

class CompositeView : public View
{
public:
    CompositeView();
    virtual ~CompositeView();

    virtual void SetBox(cv::Rect box);
    virtual void Display();

    void Add(View* view);
    void Remove(View* view);
private:
    std::list<View*> m_components;
};


#endif // VIEW_H
